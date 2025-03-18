#include "Cap.hpp"
#include "Parser.hpp"
#include "unistd.h"


Cap::Cap()
{
}

Cap::Cap(const Cap &copy) : Command(copy)
{
	*this = copy;
}

Cap::~Cap()
{
}

Cap &Cap::operator=(const Cap &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Cap::Cap(Data *data)
{
	this->data = data;
}

bool Cap::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("CAP")== 0;
}
std::string Cap::execute(std::string command, size_t i) // /CAP CAP * LS
{
	(void)command;
	write(data->getClients()[i].getFd(), "CAPS END\n", 10);
	write(data->getClients()[i].getFd(), "NICK rober\n", 11);
	write(data->getClients()[i].getFd(), "USER roberto * mi-pc : rober\n", 29);
	//USER tu_usuario tu_hostname * :tu_nombre_real


	return ("OK");
}
