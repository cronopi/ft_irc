#include "Nick.hpp"
#include "Parser.hpp"

Nick::Nick()
{
}

Nick::Nick(const Nick &copy) : Command(copy)
{
	*this = copy;
}

Nick::~Nick()
{
}

Nick &Nick::operator=(const Nick &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Nick::Nick(Data *data)
{
	this->data = data;
}

bool Nick::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("NICK")== 0;
}
// funcion sin terminar
std::string Nick::execute(std::string command, size_t i)
{
	std::vector<std::string> splitCommand;

	std::vector<Client>::iterator it;
	(void)command;
	for(it = data->getClients().begin(); it != data->getClients().end(); it++)
	{
		if (it->getName() == data->getClients()[i].getName())
		{
			return ("OK");
		}
	}
	if(it == data->getClients().end())
	{
		std::cout << "Client not found" << std::endl;
		return ("ERROR");
	}
	return ("OK");
}
