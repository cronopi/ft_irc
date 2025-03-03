#include "List.hpp"
#include "Parser.hpp"

List::List()
{
}

List::List(const List &copy) : Command(copy)
{
	*this = copy;
}

List::~List()
{
}

List &List::operator=(const List &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

List::List(Data *data):Command(data)
{
	std::cout << "constructor de join: " << data << std::endl;
	std::cout << "numro de clientes en el constructor de JOIN: " << data->getClients().size() << std::endl;
}

bool List::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("LIST")== 0;
}

std::string List::execute(std::string command, size_t i) // std::string clientName
{
	unsigned int posChannels = 0;
	(void)command;
	(void)i;
	while((posChannels < data->getChannels().size()) != 0)
	{
		std::cout << "list of public channels:" << std::endl;
		std::cout << data->getChannels()[posChannels].getName() << std::endl;
		posChannels++;
	}
	return ("OK");
}
