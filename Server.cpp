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

Server::Server(int port, std::string host) : port(port), host(host)
{

}

void Server::ServerInit()
{
	servidor_fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (servidor_fd_socket < 0)
		throw std::runtime_error("Error: socket creation failed");
	std::cout << "Socket created" << std::endl;
	// el socket se utiliza para escuchar, aceptar conexiones, enviar y recibir datos de clientes

	// el "add" es una estructura de tipo sockaddr_in que almacena direccion IP y el puerto del servidor
	add.sin_family = AF_INET; // familia del protocolo del IPV4
	add.sin_port = htons(port); // especifica el puerto del servidor y la funcion htons convierte el numero de host a un numero de red
	add.sin_addr.s_addr = INADDR_ANY; // direccion ip del servidor

	if(bind(servidor_fd_socket, (struct sockaddr *)&add, sizeof(add)) < 0) // une la direccion IP y el puerto del servidorº
	{
		std::cerr << "Error al unirse a la dirección IP y puerto" << std::endl;
		throw std::runtime_error("Error: bind failed");
	}

	if (listen(servidor_fd_socket, 10) <0) // está listo para escuchar conexiones entrantes
		throw std::runtime_error("Error: listen failed");

	std::cout << "Server listening on port " << port << std::endl;

	new_cli.fd = servidor_fd_socket;
	new_cli.events = POLLIN;
	new_cli.revents = 0;

	fds.push_back(new_cli);

	std::cout << "Server <" << servidor_fd_socket << "> Connected" << std::endl;


	std::cout << "esto espera clientes como si una recepcion de un hotel fuera" << std::endl;
	while (Server::signal == false)
	{
		if((poll(&fds[0],fds.size(),-1) == -1) && Server::signal == false)
			throw(std::runtime_error("poll() failed"));
		for (size_t i = 0; i < fds.size(); i++)
		{
			if (fds[i].revents & POLLIN)
			{
				if (fds[i].fd == servidor_fd_socket)
					this->acceptClients();
				//else
					//this->reciveNewData(fds[i].fd);
			}
		}
	}
	//close_fds();
} // aquí ya hemos rellenado la nueva ficha de los clientes o actualizado sus datos


void Server::acceptClients()
{

}

void Server::acceptConnections()
{

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
