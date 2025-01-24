#include "Command.hpp"

Command::Command()
{
}

Command::Command(const Command &copy)
{
	*this = copy;
}

Command::~Command()
{
}

Command &Command::operator=(const Command &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}


