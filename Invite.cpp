#include "Invite.hpp"
#include "Parser.hpp"
#include "unistd.h"


Invite::Invite()
{
}

Invite::Invite(const Invite &copy) : Command(copy)
{
	*this = copy;
}

Invite::~Invite()
{
}

Invite &Invite::operator=(const Invite &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Invite::Invite(Data *data)
{
	this->data = data;
}

bool Invite::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("INVITE")== 0;
}
//sin terminar
std::string Invite::execute(std::string command, size_t i)
{
	//TOPIC <canal> <user>
	std::vector<std::string> splitCommand = split(command);
	std::string channelName = splitCommand[1];
	std::string invitedClientName = splitCommand[2];
	unsigned int posChannels = 0;
	while (posChannels < data->getChannels().size() && data->getChannels()[posChannels].getName().compare(channelName) != 0)
	{
		posChannels++;
	}
	if (posChannels == data->getChannels().size())
	{
		Channel c(channelName);
		data->getChannels().push_back(c);
	}
	if (i < data->getClients().size())
	{
		data->getClients()[i].AddChannel(channelName);
		//enviar un mensaje
/* 		std::string b = "You are invited to the channel: ";
		b = b + channelName;
		write(data.getClients()[posCliente].getFd(),b.c_str(),b.length()+1); */
	}
	else
		return "ERROR: Cliente no encontrado";

	return ("OK");
}
