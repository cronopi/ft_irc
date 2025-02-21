#ifndef DATA_HPP
# define DATA_HPP

#include <vector> //-> for vector
#include "Channel.hpp"
#include "Client.hpp"

class Data
{
	private:
		std::string name;
		std::vector<Client> clients;
		std::vector<Channel> channels;
		std::vector<std::string> operators;

	public:
		Data();
		Data(Data &copy);
		virtual ~Data();
		Data &operator=(Data &copy);

		std::vector<Client> &getClients();
		std::vector<Channel> &getChannels();
		std::vector<std::string> getOperators();

};
#endif
