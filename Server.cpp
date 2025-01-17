#include "Server.hpp"

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
	port = copy.port;
	host = copy.host;
	return (*this);
}

Server::Server(int port, std::string pasword) : port(port), _password(pasword)
{
}

void Server::ServerInit()
{
	struct sockaddr_in cli_addr;
	int clientsock_fd;
	socklen_t clilen;

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
		clientsock_fd = accept(servidor_fd_socket,(struct sockaddr*) &cli_addr, &clilen);
		if (clientsock_fd > 0)
		{
			std::cout << "Conexion entrante en socket " << clientsock_fd << std::endl;

			std::cout << "IP del cliente: " << inet_ntoa(cli_addr.sin_addr) << std::endl;
			Client c( clientsock_fd, cli_addr);
			clients.push_back(c);
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
			for( i=0; i<clients.size(); i++)
			{
				if(pfds[i].revents>0)
				{
					//Connection closed
					// Remove client
				}
			}
			//recibir el mensaje
			//hacer lo mismo pero con POLLIN
		}
		sleep(1);
		if ( Server::signal )
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
