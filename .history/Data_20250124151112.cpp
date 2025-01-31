#include "Data.hpp"

Data::Data()
{

}

Data::~Data()
{

}

Data::Data(const Data &copy) : clients(copy.clients), channels(copy.channels)
{

}

Data &Data::operator=(const Data &copy)
{
    if (this != &copy) {
        clients = copy.clients;
        channels = copy.channels;
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
