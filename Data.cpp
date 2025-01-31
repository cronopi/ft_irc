#include "Data.hpp"

Data::Data()
{
	operators.push_back("roberto");
}

Data::~Data()
{
}

Data::Data(const Data &copy) : clients(copy.clients), channels(copy.channels)
{
	this->operators = copy.operators;
}

Data &Data::operator=(const Data &copy)
{
	if (this != &copy)
	{
		clients = copy.clients;
		channels = copy.channels;
		operators = copy.operators;
	}
	return *this;
}

std::vector<Client> &Data::getClients()
{
	return clients;
}

std::vector<Channel> &Data::getChannels()
{
	return channels;
}

std::vector<std::string> Data::getOperators()
{
	return operators;
}
