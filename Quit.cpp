#include "Quit.hpp"
#include "Parser.hpp"

Quit::Quit()
{
}

Quit::~Quit()
{
}

Quit::Quit(const Quit &copy) : Command(copy)
{
	*this = copy;
}

Quit &Quit::operator=(const Quit &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}


Quit::Quit(Data *data)
{
	this->data = data;
}

bool Quit::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("QUIT")== 0;
}


//sin hacer
std::string Quit::execute(std::string command, size_t i)
{
	std::vector<std::string> result;
	std::string QuitClient;
	(void)i;

	result = split(command);
	QuitClient = result[1];
	//eliminar al cliente de la lista
	for (std::vector<Client>::iterator it = data->getClients().begin(); it != data->getClients().end(); it++)
	{
		if (it->getName() == QuitClient)
		{
			data->getClients().erase(it);
			break;
		}
	}
	//eliminar al cliente de los canales
	for (std::vector<Channel>::iterator it = data->getChannels().begin(); it != data->getChannels().end(); it++)
	{

	}


	return "OK";
}
