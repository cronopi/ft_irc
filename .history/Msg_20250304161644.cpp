#include "Msg.hpp"
#include "Parser.hpp"

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
	int posChannel;

	splitCommand = split(command);
	channel = splitCommand[1];
	message = splitCommand[2];
	posChannel = 0;
	while(posChannel < data->getChannels().size() && data->getChannels()[posChannel].getName().compare(channel) != 0)
	{
		posChannel++;
	}


	return ("OK");
}
