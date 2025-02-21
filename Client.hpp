#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <iostream>
#include <netinet/in.h> //-> for sockaddr_in


class Client
{
	private:
		std::string name;
		std::string nickname;
		int fd;
		struct sockaddr_in addr;
		std::string channel;
	public:
		Client();
		Client(const Client &copy);
		~Client();
		Client &operator=(const Client &copy);

		Client(int fd, struct sockaddr_in addr);
		int getFd();
		void setFd(int fd);
		std::string getName();
		std::string getChannel();
		std::string getNick();

		struct sockaddr_in getAddr() const;
		void setAddr(struct sockaddr_in addr);
		void setChannel(std::string channel);
		void setName(std::string name);
		void setNick(std::string nickname);

};
#endif
