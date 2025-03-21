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
	this->name = copy.name;
	this->topic = copy.name;
	this->inviteOnly = copy.inviteOnly;
	this->topicRestricted = copy.topicRestricted;
	this->Password = copy.Password;
	this->maxUsers = copy.maxUsers;
	return (*this);
}

Channel::Channel(std::string name)
{
	Password		= "";
	topic			= "";
	maxUsers		= -1;
	topicRestricted = 0;
	inviteOnly		= 0;
	this->name		= name;
	//operator privilage
}

std::string Channel::getName()
{
	std::cout << "estoy imprimiendo en el getname "<< name << std::endl;
	return (name);
}

void Channel::setName(std::string name)
{
	this->name = name;
}

std::string Channel::getTopic()
{
	return (topic);
}

void Channel::setTopic(std::string topic)
{
	this->topic = topic;
}

unsigned int Channel::getMaxUsers()
{
	return (maxUsers);
}

void Channel::setMaxUsers(unsigned int maxUsers)
{
	this->maxUsers = maxUsers;
}

bool	Channel::getInviteOnly()
{
	return (inviteOnly);
}

void Channel::setInviteOnly(bool inviteOnly)
{
	this->inviteOnly = inviteOnly;
}

std::string Channel::getPassword()
{
	return (Password);
}

void Channel::setPassword(std::string password)
{
	this->Password = password;
}
