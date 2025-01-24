#include "Channel.hpp"

Channel::Channel()
{
}

Channel::~Channel()
{
}

Channel::Channel(const Channel &copy)
{
	*this = copy;
}

Channel &Channel::operator=(const Channel &copy)
{
	(void)copy;
	return (*this);
}

Channel::Channel(std::string name) :name(name)
{

}

std::string Channel::getName()
{
	return (name);
}
