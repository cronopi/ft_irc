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

Join::Join(Data *data):Command(data)
{
	std::cout << "constructor de join: " << data << std::endl;
	std::cout << "numro de clientes en el constructor de JOIN: " << data->getClients().size() << std::endl;
}

bool Join::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("JOIN")== 0;
}

std::string Join::execute(std::string command, size_t i) // std::string clientName
{
	std::string channelName;
	std::vector<std::string> result;

	result = split(command);
	channelName = result[1];

	unsigned int posChannels = 0;
	while(posChannels < data->getChannels().size() && data->getChannels()[posChannels].getName().compare(channelName) != 0)
	{
		posChannels++;
	}
	if(posChannels == data->getChannels().size())
	{
		Channel c(channelName);
		data->getChannels().push_back(c);
	}
	data->getClients()[i].AddChannel(channelName);
	return ("OK");
}
