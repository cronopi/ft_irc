#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include "Data.hpp"
#include "Command.hpp"
#include "Channel.hpp"
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

#include "Invite.hpp"
#include "Kick.hpp"
#include "Mode.hpp"
#include "Nick.hpp"
#include "Join.hpp"
#include "Part.hpp"
#include "Quit.hpp"
#include "Topic.hpp"
#include "Register.hpp"
#include "Registry.hpp"
#include "Privmsg.hpp"
#include "User.hpp"
#include "Msg.hpp"
#include "List.hpp"

class Server
{
	private:
		int port;
		std::string _password;
		static bool signal;
		std::string host;
		struct sockaddr_in add;
		int servidor_fd_socket;
		Data *data;
		std::vector<Command*> availableCommands;


		static const int MAXCLIENTS = 200;

		class SignalException : public std::exception
		{
			virtual const char *what() const throw();
		};

		std::string execute(std::string command, size_t i);
	public:
		Server();
		Server(Server &copy);
		~Server();
		Server &operator=(Server &copy);

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
