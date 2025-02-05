#include "Server.hpp"
#include <cerrno>
#include <cstdio>
#include <cstring>

Server::Server()
{
}

Server::~Server()
{
}

Server::Server(const Server &copy)
{
	*this = copy;
}

Server &Server::operator=(const Server &copy)
{
	data=copy.data;
	port = copy.port;
	host = copy.host;
	return (*this);
}

Server::Server(int port, std::string pasword) : port(port), _password(pasword)
{
	availableCommands.push_back(new Join(data));
	availableCommands.push_back(new Invite(data));
	availableCommands.push_back(new Kick(data));
	availableCommands.push_back(new Mode(data));
	availableCommands.push_back(new Nick(data));
	availableCommands.push_back(new Part(data));
	availableCommands.push_back(new Quit(data));
	availableCommands.push_back(new Topic(data));
}

void Server::ServerInit()
{
	struct sockaddr_in cli_addr;
	int clientsock_fd;
	socklen_t clilen;
	std::vector<Client> clients = data.getClients();

	servidor_fd_socket = socket(AF_INET, SOCK_STREAM, 0); // IPPROTO_TCP = 0  en este caso. cuando pasamos 0 el sistema escoge el protocolo por defecto
	if (servidor_fd_socket < 0)
		throw std::runtime_error("Error: socket creation failed");
	std::cout << "Socket created" << std::endl; // el socket se utiliza para escuchar, aceptar conexiones, enviar y recibir datos de clientes

	// esto permite que el socket reutilice la dirección IP y puerto que ya está en uso por otro proceso.

	int en = 1;
 	if(setsockopt(servidor_fd_socket, SOL_SOCKET, SO_REUSEADDR, &en, sizeof(en)) == -1)
		throw(std::runtime_error("failed to set the reuse of the address"));

	if (fcntl(servidor_fd_socket, F_SETFL, O_NONBLOCK) == -1) // establece el socket en modo no bloqueante
		throw std::runtime_error("failed to create a nonblocking socket");

	// el "add" es una estructura de tipo sockaddr_in que almacena direccion IP y el puerto del servidor
	add.sin_family = AF_INET; // familia del protocolo del IPV4
	add.sin_port = htons(port); // especifica el puerto del servidor y la funcion htons convierte el numero de host a un numero de red
	add.sin_addr.s_addr = INADDR_ANY; // direccion ip del servidor

	if(bind(servidor_fd_socket, (struct sockaddr *)&add, sizeof(add)) < 0) // une la direccion IP y el puerto del servidorº
	{
		std::cerr << "Error al unirse a la dirección IP y puerto" << std::endl;
		throw std::runtime_error("Error: bind failed");
	}
	if (listen(servidor_fd_socket, 10) < 0) // está listo para escuchar conexiones entrantes
		throw std::runtime_error("Error: listen failed");

	std::cout << "Server listening on port " << port << std::endl;

	while(true)
	{
		// acepta una nueva conexion, devuelve el socket de la conexion y la direccion del cliente
		clientsock_fd = accept(servidor_fd_socket,(struct sockaddr*) &cli_addr, &clilen);
		if (clientsock_fd != -1)
		{
			std::cout << "Conexion entrante en socket " << clientsock_fd << std::endl;
			std::cout << "IP del cliente: " << inet_ntoa(cli_addr.sin_addr) << std::endl;
			Client c( clientsock_fd, cli_addr);
			clients.push_back(c);
		}
		std::cout << "tamaño del array de clients: " << clients.size() << std::endl;

		struct pollfd *pfds;
		pfds = new struct pollfd[clients.size()];
		size_t i = 0;
		for (i = 0; i < clients.size(); i++)
		{
			pfds[i].fd = clients[i].getFd();
			pfds[i].events = POLLHUP;
			pfds[i].revents = 0;
		}
		poll(pfds,clients.size(),0);
		std::vector<size_t> posToDelete;
		for (i = 0; i < clients.size(); i++)
		{
			if(pfds[i].revents > 0)
			{
				//Connection closed and Remove client
				close(clients[i].getFd());
				posToDelete.push_back(i);
			}
		}
		delete[] pfds;
		for(i  = 0; i< posToDelete.size(); i++){
			clients.erase(clients.begin() + posToDelete[i]);
		}
		//recibir el mensaje, hacer lo mismo pero con POLLIN
		pfds = new struct pollfd[clients.size()];
		for (i = 0; i < clients.size(); i++)
		{
			pfds[i].fd = clients[i].getFd();
			pfds[i].events = POLLIN; // Cambia a POLLIN para recibir el mensaje
			pfds[i].revents = 0;
		}
		poll(pfds, clients.size(), 0);
		for (i = 0; i < clients.size(); i++)
		{
			if (pfds[i].revents > 0)
			{
				std::cout << "entrada al if" << std::endl;

				std::string message2;
				char buffer[1025] = {0};
				int bytes_leidos = read(pfds[i].fd, buffer, 1024);
				if (bytes_leidos == -1)
					std::cout << "error en el read(1)" << std::endl;
				buffer[bytes_leidos] = 0;
				std::cout << "test bytes leidos: "<< bytes_leidos << "  file descriptor: " << pfds[i].fd << "  buffer: "<< buffer <<  std::endl;
				if(bytes_leidos > 0)
				{
					std::cout << "entrada al bucle" << std::endl;
					int l = strlen(buffer);
					std::cout << "tamaño de l:" << l << std::endl;
					message2.assign(buffer, bytes_leidos);
					std::cout << "test message assing:" << message2 << std::endl;
				}
				std::cout << "he salido del bucle e imprimo message 2: " << message2 << std::endl;
				std::string result = execute(message2, clients[i].getName());
				std::cout << "imprime result: " << result << std::endl;
				if(result.compare("OK"))
				{
					// NO hacer nada?
				}
				else
					write(clients[i].getFd(), result.c_str(), result.size() + 1);
			}
		}
		sleep(2);
		if (Server::signal)
		{
			exit(0);
		}
	}
}

void Server::CloseServer()
{
	if (servidor_fd_socket != -1)
	{
		close(servidor_fd_socket);
	}
}

std::string Server::execute(std::string command,std::string clientName)
{
	std::string result;
	unsigned int posCommand = 0;
	while(posCommand<availableCommands.size() && !availableCommands[posCommand]->handles(command))
	{
		posCommand++;
	}
	std::cout << "posCommand: " << posCommand << std::endl;
	if(posCommand==availableCommands.size())
	{
		std::cout << "entrando en el if" << std::endl;
		return "INVALID COMMAND: '"+command+"'";
	}
	else
	{
		std::cout << "entrando en el else" << std::endl;
		return availableCommands[posCommand]->execute(command, clientName);
	}

}

const char *Server::SignalException::what() const throw()
{
	return ("SignalExcepcion");
}
bool Server::signal = false;
void Server::sigHandler(int sig)
{
	(void)sig;
	std::cout << std::endl << "Signal Received in sigHandler!" << std::endl;
	Server::signal = true;
	throw Server::SignalException();
}
