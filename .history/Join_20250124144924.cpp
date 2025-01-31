#include "Join.hpp"

Join::Join()
{
}

Join::Join(const Join &copy)
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
	//si no lo trimmea tengo que gestionarlo yo
	return command.substr(0,4).compare("JOIN")==0;
}

std::string Join::execute(std::string command, std::string clientName)
{
	//ver si tengo que trimmear el IsSpace() o lo gestiona el cliente
	// manejar el join en caso de que no me pasen ningún canal

	std::string channel_name;

	channel_name = command.substr(5);

	return ;
}
