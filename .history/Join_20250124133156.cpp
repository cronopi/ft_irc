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

bool Join::handles(std::string Command)
{

}
