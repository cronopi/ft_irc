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
	maxUsers = -1;
}

std::string Channel::getName()
{
	return (name);
}

std::string Channel::getTopic()
{
	return (topic);
}

std::string Channel::setTopic(std::string topic)
{
	this->topic = topic;
}
