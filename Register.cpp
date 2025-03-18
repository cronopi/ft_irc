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

std::string Register::execute(std::string command, size_t i) // USER NICKNAME AND PASSWORD
{
	std::vector<std::string> registerUser;
	std::string user;
	std::string nickName;
	std::string password;
	Registry	reg;

	registerUser = split(command);
	user = registerUser[1];
	nickName = registerUser[2];
	password = registerUser[3];

	if (user.empty() || nickName.empty() || password.empty())
	{
		return "ERROR: user, nickName or password cannot be empty";
	}
	if (reg.registerUser(user, password, nickName))
	{
		Client cli;
		data->getClients()[i].setName(user);
		data->getClients()[i].setNick(user);
	}
	return "OK";
}
