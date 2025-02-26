#include "User.hpp"
#include "Parser.hpp"
#include "unistd.h"
#include "Registry.hpp"

User::User()
{
}

User::User(const User &copy) : Command(copy)
{
	*this = copy;
}

User::~User()
{
}

User &User::operator=(const User &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

User::User(Data *data)
{
	this->data = data;
}

bool User::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("USER")== 0;
}

std::string User::execute(std::string command, size_t i) //  usuario y contraseña
{
	std::vector<std::string> userLogin;
	std::string user;
	std::string password;
	Registry reg;
	std::string nick;

	userLogin = split(command);
	user = userLogin[1];
	password = userLogin[2];
	if (reg.authenticateUser(user, password))
	{
		nick = reg.readNick(user);
		data->getClients()[i].setNick(nick);
		return "OK";
	}
	else
	{
		return "ERROR: User not found";
	}
	return "";
}
