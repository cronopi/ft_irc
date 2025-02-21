#include "Registry.hpp"
#include "Parser.hpp"
#include "unistd.h"
#include <iostream>
#include <fstream>

Registry::Registry()
{
}

Registry::Registry(const Registry &copy)
{
	*this = copy;
}

Registry::~Registry()
{
}

Registry &Registry::operator=(const Registry &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

bool Registry::registerUser(std::string newUser, std::string password, std::string nickname)
{

	std::ifstream f("users.csv");

	unsigned int i = 0;


	if( f.is_open() )
	{
		std::string linea;
		while(f >> linea)
		{
			std::vector <std::string> split_line = split_semicolon(linea);
			if(split_line[0].compare(newUser)==0 || split_line[1].compare(newUser)==0){
				f.close();
				return false;
			}
		}
		f.close();
	}
	else
	{
		// abortar ejecucion
	}

	std::ofstream file("users.csv", std::ios_base::app);

	if (file.is_open())
	{
		std::cout << "archivo abierto" << std::endl;

		file << newUser << ";" << nickname << ";" << password << std::endl;

		file.close();
		return true;
	}
	else
	{
		std::cout << "Error: cannot open the file" << std::endl;
		// abortar el servidor
	}
}

bool authenticateUser(std::string user, std::string password)
{
	std::ifstream				f("users.csv");
	std::vector<std::string>	split_line;
	std::string					linea;

	if (f.is_open())
	{
		while (f >> linea)
		{
			split_line = split_semicolon(linea);
			if (split_line[0].compare(user) == 0 && split_line[2].compare(password) == 0)
			{
				f.close();
				return true;
			}
		}
		f.close();
	}
	else
	{
		// abortar ejecucion
	}

	return false;
}

void changePassword(std::string user, std::string newPass)
{
	std::ifstream f("users.csv");
	std::ofstream aux("aux.csv");
	std::vector<std::string> split_line;
	std::string line;

	if (!f.is_open())
	{
		// abortar ejecucion
	}
	else
	{
		while(f >> line)
		{
			split_line = split_semicolon(line);
			if (split_line[0].compare(user) == 0 )
			{
				aux << split_line[0]  <<  ";" <<  split_line[1] <<  ";" << newPass << std::endl;
			}
			else
			{
				aux << line << std::endl;
			}
		}
		f.close();
		aux.close();
		if (std::remove("users.csv") != 0)
		{
			std::cout << "error al borrar el archivo" << std::endl;
			//abortar ejecucion
		}
		if(std::rename("aux.csv", "users.csv") != 0)
		{
			std::cout << "error al renombrar el archivo" << std::endl;
			//abortar ejecucion
		}
	}
}
