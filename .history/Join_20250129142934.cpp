#include "Join.hpp"
#include "Parser.hpp"

Join::Join()
{
}

Join::Join(const Join &copy) : Command(copy)
{
	*this = copy;
}

Join::~Join()
{
}

Join &Join::operator=(const Join &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Join::Join(Data &data)
{
	this->data = data;
}

bool Join::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("JOIN")== 0;
}

std::string Join::execute(std::string command, std::string clientName)
{

	std::string channelName;
	std::vector<std::string> result;
	unsigned int posCliente;

	result = split(command);
	channelName = result[1];
	posCliente = 0;
	while(posCliente<data.getClients().size() && data.getClients()[posCliente].getName().compare(clientName) != 0)
	{
		posCliente++;
	}
	unsigned int posChannels = 0;
	while(posChannels < data.getChannels().size() && data.getChannels()[posCliente].getName().compare(channelName) != 0)
	{
		posChannels++;
	}

	if(posChannels == data.getChannels().size()){
		Channel c(channelName);
		data.getChannels().push_back(c);
	}

	data.getClients()[posCliente].setChannel(channelName);

	return ("OK");
}
