#ifndef KICK_HPP
# define KICK_HPP

#include <iostream>
#include "Command.hpp"


class Kick : public Command
{
	private:

	public:
		Kick();
		Kick(const Kick &copy);
		virtual ~Kick();
		Kick &operator=(const Kick &copy);

		Kick(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
