#include "Parser.hpp"

void	trimIsSpace(std::string &s)
{
	s.erase(0, s.find_first_not_of("\t\n\v\f\r "));
	s.erase(s.find_last_not_of("\t\n\v\f\r ") + 1);
}

bool findCommand(std::string str)
{
	std::string command[] = {"JOIN", "INVITE", "QUIT"};

// NO ENTIENDO POR QUÉ ESTO ES ASÍ i < sizeof(command) / sizeof(command[0])
	for (unsigned int i = 0; i < sizeof(command) / sizeof(command[0]); i++)
	{
		if (str.find(command[i]) == 0)
		{
			std::cout << "command found" << std::endl;
			return (1);
		}
	}
	std::cout << "command not found" << std::endl;
	return (0);
}

std::vector<std::string> split(std::string str) // JOIN CHANNEL
{
	std::vector<std::string> result;

	size_t start = 0;
	for(size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]))
		{
			if (i > start)
				result.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}
	if (start < str.length())
		result.push_back(str.substr(start));

	return (result);
}

void handleCommands(std::vector<std::string> command)
{
	if (findCommand(command[0]) == 0)
		std::cout << "command not found" << std::endl;

	//Join join;

	if (command[0] == "JOIN")
		std::cout << "entrando en la funcion de join" << std::endl;
	if (command[0] == "QUIT")
		std::cout << "entrando en la funcion de quit" << std::endl;
	if (command[0] == "INVITE")
		std::cout << "entrando en la funcion de invite" << std::endl;
}
