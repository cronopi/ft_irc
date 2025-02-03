#include "Mode.hpp"
#include "Parser.hpp"

Mode::Mode()
{
}

Mode::Mode(const Mode &copy) : Command(copy)
{
	*this = copy;
}

Mode::~Mode()
{
}

Mode &Mode::operator=(const Mode &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Mode::Mode(Data &data)
{
	this->data = data;
}

bool Mode::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("MODE")== 0;
}

std::string Mode::execute(std::string command, std::string clientName)
{
	// estructura -> MODE <canal o usuario> [+|-]<modo> [<argumento>]
	std::vector <std::string> splitCommand = split(command);
	std::string channelName = splitCommand[1];
	std::string mode = splitCommand[2];
	std::string argument = splitCommand[3];

	if (mode[2] == '+i' || mode[2] == '-i')
	{
		if (mode.find('+') != std::string::npos)
		{
			//canal solo mediante invite
		}
		else if (mode.find('-') != std::string::npos)
		{
			//canal mediante join e invite
		}
	}
	else if (mode[2] == '+t' || mode[2] == '-t')
	{
		if (mode.find('+') != std::string::npos)
		{
			//canal solo mediante
		}
		else if (mode.find('-') != std::string::npos)
		{
			//canal mediante join e invite
		}
	}
	else if (mode[2] == '+k' || mode[2] == '-k')
	{
		if (mode.find('+') != std::string::npos)
		{
			//canal solo mediante contraseña
		}
		else if (mode.find('-') != std::string::npos)
		{
			//canal sin contraseña
		}
	}
	else if (mode[2] == '+o' || mode[2] == '-o')
	{
		if (mode.find('+') != std::string::npos)
		{
			//canal con permiso de operador
		}
		else if (mode.find('-') != std::string::npos)
		{
			//canal sin permiso de operador
		}
	}
	else if (mode[2] == '+l' || mode[2] == '-l')
	{
		if (mode.find('+') != std::string::npos)
		{
			//canal con max de usuarios
		}
		else if (mode.find('-') != std::string::npos)
		{
			//canal sin maximo de usuarios
		}
	}
	else
		return "Error: MODE not found";

	return ("OK");
}
