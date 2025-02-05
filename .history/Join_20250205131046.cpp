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

	std::cout << "antes del split" << std::endl;
	result = split(command);
	std::cout << "despues del split" << std::endl;
	channelName = result[1];
	posCliente = 0;
	while(posCliente<data.getClients().size() && data.getClients()[posCliente].getName().compare(clientName) != 0)
	{
		posCliente++;
	}
	std::cout << "despues del while de cliente, posicion del cliente" << posCliente << std::endl;
	unsigned int posChannels = 0;
	while(posChannels < data.getChannels().size() && data.getChannels()[posCliente].getName().compare(channelName) != 0)
	{
		posChannels++;
	}
	std::cout << "despues del while de channel" << std::endl;
	if(posChannels == data.getChannels().size())
	{
		std::cout << "dentro del if en poschannels" << std::endl;
		Channel c(channelName);
		std::cout << "INICIALIZAR CHANNEL" << std::endl;
		data.getChannels().push_back(c);
		std::cout << "despues del push back, seguimos dentro del if" << std::endl;
	}

	data.getClients()[posCliente].setChannel(channelName);
	std::cout << "despues de data clients to channel" << std::endl;


	return ("OK");
}
