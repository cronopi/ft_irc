#ifndef QUIT_HPP
# define QUIT_HPP

#include <iostream>
#include "Command.hpp"


class Quit : public Command
{
	private:

	public:
		Quit();
		Quit(const Quit &copy);
		virtual ~Quit();
		Quit &operator=(const Quit &copy);

		Quit(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
