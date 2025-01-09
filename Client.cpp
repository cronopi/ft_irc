#include "Client.hpp"

Client::Client()
{
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
		this->IP = copy.IP;
	}
	return (*this);
}


int Client::getFd()
{
	return (fd);
}

void Client::setFd(int fd)
{
	this->fd = fd;
}

std::string Client::getIP() const
{
	return (IP);
}

void Client::setIP(std::string IP)
{
	this->IP = IP;
}
