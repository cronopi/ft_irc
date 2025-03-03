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

Part::Part(Data *data)
{
	this->data = data;
}

bool Part::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("PART")== 0;
}

std::string Part::execute(std::string command, size_t i) // /PART <Channel> <message>
{
	std::vector<std::string> splitCommand;
	std::string channelName;
	unsigned int posChannel;

	splitCommand = split(command);
	channelName = splitCommand[1];
	posChannel = 0;
	for (std::vector<Client>::iterator it = data->getClients().begin(); it != data->getClients().end(); it++)
	{
		if (it->getName() == data->getClients()[i].getName())
		{
			while (posChannel < data->getClients()[i].getChannel().size())
			{
				if (data->getClients()[i].getChannel()[posChannel].compare(channelName) == 0)
				{
					std::cout << "el canal existe y debemos salir" << std::endl;
					data->getClients()[i].getChannel()[posChannel].erase();
				}
				posChannel++;
			}
			/* if(it->getChannel().compare("") != 0)
			{
				it->setChannel("");
				return "OK";
			}
			else
			{
				return "Not in any channel";
			}
			*/
		}
	}
	return "client not found";
}
