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

Mode::Mode(Data *data)
{
	this->data = data;
}

bool Mode::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("MODE")== 0;
}

std::string Mode::execute(std::string command, size_t i) // std::string clientName
{
	// estructura -> MODE <canal o usuario> [+|-]<modo> [<argumento>]
	std::vector <std::string> splitCommand = split(command);
	std::string channelName = splitCommand[1];
	std::string mode = splitCommand[2];
	std::string argument = splitCommand[3];
	(void)i;

	if (mode.compare("+i") == 0 || mode.compare("-i") == 0)
	{
		if (mode[0] == '+')
		{
			//canal solo mediante invite
		}
		else if (mode[0] == '-')
		{
			//canal mediante join e invite
		}
	}
	else if (mode.compare("+t") == 0 || mode.compare("-t") == 0)
	{
		if (mode[0] == '+')
		{
			//canal solo mediante
		}
		else if (mode[0] == '-')
		{
			//canal mediante join e invite
		}
	}
	else if (mode.compare("+k") == 0 || mode.compare("-k") == 0)
	{
		if (mode[0] == '+')
		{
			//canal solo mediante contraseña
		}
		else if (mode[0] == '-')
		{
			//canal sin contraseña
		}
	}
	else if (mode.compare("+o") == 0 || mode.compare("-o") == 0)
	{
		if (mode[0] == '+')
		{
			//canal con permiso de operador
		}
		else if (mode[0] == '-')
		{
			//canal sin permiso de operador
		}
	}
	else if (mode.compare("+l") == 0 || mode.compare("-l") == 0)
	{
		if (mode[0] == '+')
		{
			//canal con max de usuarios
		}
		else if (mode[0] == '-')
		{
			//canal sin maximo de usuarios
		}
	}
	else
		return "Error: MODE not found";

	return ("OK");
}
