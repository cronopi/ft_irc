#include "Server.hpp"
#include "Join.hpp"
#include "Data.hpp"

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

/*
Un cliente IRC es un programa que se conecta a un servidor IRC y permite
a los usuarios interactuar con el servidor y con otros usuarios.
Hay muchos clientes IRC existentes que puedes utilizar. Los estudiantes de
42 más recientes han aprendido a usar el cliente de IRC de hexchat.

Una vez instalado Hexchat necesito configuar el servidor(entiendo que es local)
Para ello será necesario la dirección IP del servidor,el puerto y nombre de la red(no estoy seguro)

Para conectar al servidor seguir estos pasos:

https://wiki.znc.in/HexChat



The way file transfer works over IRC Is via DCC (direct client to client),
so no actual file Is stored in the server. It Is really easy to implement as
It Is Simply a command handled by hexchat only. And you can test It via hexchat
directly by sending a file from localhost to localhost.





Qué es el birdcd?
A basic TCP server. It's an exemple of how to use the function. doesn't implement any IRC specific.

*/
