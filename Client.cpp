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
		this->addr = copy.addr;
	}
	return (*this);
}

Client::Client(int fd, struct sockaddr_in addr): fd(fd), addr(addr)
{

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

void Client::setAddr(struct sockaddr_in addr)
{
	this->addr = addr;
}
