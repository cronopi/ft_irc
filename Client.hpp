#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Server.hpp"
#include <netinet/in.h> //-> for sockaddr_in


class Client
{
	private:
		int fd;
		struct sockaddr_in addr;
	public:
		Client();
		Client(const Client &copy);
		~Client();
		Client &operator=(const Client &copy);

		Client(int fd, struct sockaddr_in addr);
		int getFd();
		void setFd(int fd);
		struct sockaddr_in getAddr() const;
		void setAddr(struct sockaddr_in addr);
};
#endif
