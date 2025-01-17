#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>

/* #include "User.hpp"
#include "Channel.hpp"
#include "Reply.hpp"
#include "Command.hpp" */
#include "Client.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring> //-> for memset
#include <vector> //-> for vector
#include <sys/socket.h> //-> for socket()
#include <sys/types.h> //-> for socket()
#include <netinet/in.h> //-> for sockaddr_in
#include <fcntl.h> //-> for fcntl()
#include <unistd.h> //-> for close()
#include <arpa/inet.h> //-> for inet_ntoa()
#include <poll.h> //-> for poll()
#include <csignal> //-> for signal()
//-------------------------------------------------------//

class Client;


class Server
{
	private:
		int port;
		std::string _password;
		static bool signal;
		std::string host;
		struct sockaddr_in add;
		int servidor_fd_socket;
		std::vector<Client> clients;

		//std::vector<Channel> channels;
		//std::vector <struct pollfd> fds;
		static const int MAXCLIENTS = 200;



		class SignalException : public std::exception
		{
			virtual const char *what() const throw();
		};
	public:
		Server();
		Server(const Server &copy);
		~Server();
		Server &operator=(const Server &copy);

		Server(int port, std::string host);
		void acceptConnections();
		void acceptClients();
		void reciveNewData(int fd);
		void ClearClients(int fd);
		void handleMessage(std::string message);
		void CloseServer();
		void ServerInit();

		static void sigHandler(int sig);

};
#endif
