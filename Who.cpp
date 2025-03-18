#include "Who.hpp"
#include "Parser.hpp"
#include "unistd.h"
#include "Registry.hpp"

Who::Who()
{
}

Who::Who(const Who &copy) : Command(copy)
{
	*this = copy;
}

Who::~Who()
{
}

Who &Who::operator=(const Who &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Who::Who(Data *data)
{
	this->data = data;
}

bool Who::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("WHO")== 0;
}

std::string Who::execute(std::string command, size_t i)
{
	(void)i;
	(void)command;
	return "OK";
}
