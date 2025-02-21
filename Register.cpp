#include "Register.hpp"
#include "Parser.hpp"
#include "unistd.h"
#include "Registry.hpp"

Register::Register()
{
}

Register::Register(const Register &copy) : Command(copy)
{
	*this = copy;
}

Register::~Register()
{
}

Register &Register::operator=(const Register &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Register::Register(Data *data)
{
	this->data = data;
}

bool Register::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("REGISTER")== 0;
}

std::string Register::execute(std::string command, size_t i)
{
	std::vector<std::string> registerUser;
	std::string user;
	std::string nickName;
	std::string password;
	Registry reg;

	registerUser = split(command);
	user = registerUser[0];
	nickName = registerUser[1];
	password = registerUser[2];


	if (reg.registerUser(user, password, nickName))
	{
		Client cli();
		data->getClients()[i].setName(user);
		data->getClients()[i].setNick(user);
	}
}
