#include "Topic.hpp"
#include "Parser.hpp"

Topic::Topic()
{
}

Topic::Topic(const Topic &copy) : Command(copy)
{
	*this = copy;
}

Topic::~Topic()
{
}

Topic &Topic::operator=(const Topic &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Topic::Topic(Data &data)
{
	this->data = data;
}

bool Topic::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("TOPIC")== 0;
}

std::string Topic::execute(std::string command, std::string clientName)
{

	return ("OK");
}
