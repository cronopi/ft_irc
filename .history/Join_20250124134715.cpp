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
