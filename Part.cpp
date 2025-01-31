#include "Part.hpp"
#include "Parser.hpp"

Part::Part()
{
}

Part::Part(const Part &copy) : Command(copy)
{
	*this = copy;
}

Part::~Part()
{
}

Part &Part::operator=(const Part &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Part::Part(Data &data)
{
	this->data = data;
}

bool Part::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("PART")== 0;
}

std::string Part::execute(std::string command, std::string clientName)
{
	std::vector<std::string> splitCommand;
	std::string channelName;

	splitCommand = split(command);
	for (std::vector<Client>::iterator it = data.getClients().begin(); it != data.getClients().end(); it++)
	{
		if (it->getName() == clientName)
		{
			if(it->getChannel().compare("")!=0)
			{
				it->setChannel("");
				return "OK";
			}
			else
			{
				return "Not in any channel";
			}
		}
	}
	return "client not found";
}
