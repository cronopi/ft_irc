#include "Privmsg.hpp"
#include "Parser.hpp"
#include "unistd.h"
#include "Registry.hpp"

Privmsg::Privmsg()
{
}

Privmsg::Privmsg(const Privmsg &copy) : Command(copy)
{
	*this = copy;
}

Privmsg::~Privmsg()
{
}

Privmsg &Privmsg::operator=(const Privmsg &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Privmsg::Privmsg(Data *data)
{
	this->data = data;
}

bool Privmsg::handles(std::string command)
{
	std::vector<std::string> result;
	std::cout << "estoy entrando en handles de privmsg" << std::endl;

	result = split(command);
	return result[0].compare("PRIVMSG")== 0;
}

std::string Privmsg::execute(std::string command, size_t i)  // /privmsg <target> <message>
{
	std::vector<std::string> split_priv;

	split_priv = split(command);
	std::string target = split_priv[1];
	std::string message = split_priv[2];
	(void)i;

	unsigned int posClient = 0;
	std::cout << "estoy entrando en privmsg" << std::endl;
	while(posClient < data->getClients().size())
	{
		if (data->getClients()[posClient].getName().compare(target) == 0)
		{
			//std::cout << "Sending message to " << data->getClients()[posClient].getName() << std::endl;
			return "OK";
		}
		posClient++;
	}
	return "ERROR: client not found";
}
