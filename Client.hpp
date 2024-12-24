#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Server.hpp"

class Client
{
	private:
		int fd;
		std::string IP;
	public:
		Client();
		Client(const Client &copy);
		~Client();
		Client &operator=(const Client &copy);

		int getFd() const;
		void setFd(int fd);
		std::string getIP() const;
		void setIP(std::string IP);
};
#endif
