#include "Msg.hpp"
#include "Parser.hpp"
#include <unistd.h>

Msg::Msg()
{
}

Msg::Msg(const Msg &copy) : Command(copy)
{
	*this = copy;
}

Msg::~Msg()
{
}

Msg &Msg::operator=(const Msg &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Msg::Msg(Data *data):Command(data)
{
	std::cout << "constructor de join: " << data << std::endl;
	std::cout << "numro de clientes en el constructor de JOIN: " << data->getClients().size() << std::endl;
}

bool Msg::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("MSG")== 0;
}

std::string Msg::execute(std::string command, size_t i) // /msg <channel> <message>
{
	std::vector<std::string> splitCommand;
	std::string channel;
	std::string message;
	unsigned int posChannel;
	unsigned int posClient;
	unsigned int posClientChannel;

	splitCommand = split(command);
	channel = splitCommand[1];
	message = splitCommand[2] + "\n";
	posChannel = 0;
	posClient = 0;
	posClientChannel = 0;
	while(posChannel < data->getChannels().size() && data->getChannels()[posChannel].getName().compare(channel) != 0)
	{
		posChannel++;
	}
	if (posChannel < data->getChannels().size())
	{
		for(posClient=0; posClient < data->getClients().size(); posClient++)
		{
			if ( posClient != i)
			{
				for(posClientChannel = 0; posClientChannel < data->getClients()[posClient].getChannel()[posClientChannel].size(); posClientChannel++)
				{
					if (data->getClients()[posClient].getChannel()[posClientChannel].compare(channel)==0)
					{
						write(data->getClients()[posClient].getFd(), message.c_str(), message.size());
					}
				}
			}
		}
	}
	return ("OK");
}
