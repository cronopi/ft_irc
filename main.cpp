#include "Server.hpp"

int checkPort(std::string port)
{
	for (unsigned int i = 0; i < port.length(); i++)
	{
		if (port[i] < '0' || port[i] > '9')
			return (0);
	}
	return (1);
}

int main (int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
	{
		std::cerr << "Error: bad arguments" << std::endl;
		return (1);
	}
	else if (checkPort(argv[1]) == 0 ||std::atoi(argv[1]) < 1024 || std::atoi(argv[1]) > 65535)
	{
		std::cerr << "Error: bad port" << std::endl;
		return (1);
	}
	else if (std::string(argv[2]).empty() || std::string(argv[2]).length() > 10)
	{
		std::cerr << "Error: bad password" << std::endl;
	}

	std::cout << "Server started" << std::endl;
	Server server(std::atoi(argv[1]), argv[2]);
	try
	{
		signal(SIGINT, Server::sigHandler);
		signal(SIGQUIT, Server::sigHandler);
		server.ServerInit();
	}
	catch(const std::exception& e)
	{
		//aqui hay que hacer una llamada para cerrar los descriptores, liberar la memoria y cerrar el socket
		server.CloseServer();
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Server closed" << std::endl;
	return (0);
}
