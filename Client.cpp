#include "Client.hpp"

Client::Client()
{
	fd = 0;
}

Client::Client(const Client &copy)
{
	*this = copy;
}

Client::~Client()
{
}

Client &Client::operator=(const Client &copy)
{
	if (this != &copy)
	{
		this->fd = copy.fd;
		this->addr = copy.addr;
	}
	return (*this);
}

Client::Client(int fd, struct sockaddr_in addr): fd(fd), addr(addr)
{

}

std::string Client::getName()
{
	return (name);
}

std::string Client::getNick()
{
	return (nickname);
}


int Client::getFd()
{
	return (fd);
}

void Client::setFd(int fd)
{
	this->fd = fd;
}

struct sockaddr_in Client::getAddr() const
{
	return (addr);
}

std::vector<std::string> Client::getChannel()
{
	return (channel);
}

void	Client::setAddr(struct sockaddr_in addr)
{
	this->addr = addr;
}

void	Client::AddChannel(std::string channel)
{
	this->channel.push_back(channel);
}

void Client::setName(std::string name)
{
	this->name = name;
}

void Client::setNick(std::string nickname)
{
	this->nickname = nickname;
}
