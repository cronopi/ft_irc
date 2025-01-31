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

Nick::Nick(Data &data)
{
	this->data = data;
}

bool Nick::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("JOIN")== 0;
}

std::string Nick::execute(std::string command, std::string clientName)
{
	std::vector<std::string> splitCommand;

	auto it = data.getClients().begin();
	for(it; it != data.getClients().end(); it++)
	{
		if (it->getName() == clientName)
		{

			return ("OK");
		}
	}
	if(it == data.getClients().end())
	{
		std::cout << "Client not found" << std::endl;
		return ("ERROR");
	}
	return ("OK");
}
