#include "Kick.hpp"
#include "Parser.hpp"

Kick::Kick()
{
}

Kick::Kick(const Kick &copy) : Command(copy)
{
	*this = copy;
}

Kick::~Kick()
{
}

Kick &Kick::operator=(const Kick &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Kick::Kick(Data *data)
{
	this->data = data;
}

bool Kick::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("KICK")== 0;
}

std::string Kick::execute(std::string command, size_t i) // std::string clientName
{
	std::string					clientToKick;
	std::vector<std::string>	splitCommand;
	size_t posClient;
	size_t posOperator;

	splitCommand = split(command);
	clientToKick = splitCommand[1];
	posClient = 0;
	posOperator = 0;

	while(posOperator < data->getOperators().size() && data->getOperators()[posOperator].compare(data->getClients()[i].getName())==0)
	{
		posOperator++;
	}
	if(posOperator<data->getOperators().size())
	{
		while(posClient < data->getClients().size() && data->getClients()[posClient].getName().compare(clientToKick) != 0)
		{
			posClient++;
		}
		if(posClient<data->getClients().size()){
			if(data->getClients()[posClient].getChannel().compare("")!=0){
				data->getClients()[posClient].setChannel("");
				return "OK";
			}
			else{
				return "client not in any channel";
			}
		}
		else{
			return "no such client";
		}
	}
	else
		return "unaothorized";
}
