#ifndef DATA_HPP
# define DATA_HPP

#include <vector> //-> for vector
#include "Channel.hpp"
#include "Client.hpp"

class Data
{
	private:
		std::vector<Client> clients;
		std::vector<Channel> channels;

	public:
		Data();
		Data(const Data &copy);
		virtual ~Data();
		Data &operator=(const Data &copy);

		std::vector<Client> &getClients();
		std::vector<Channel> &getChannels();

};
#endif
