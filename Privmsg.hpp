#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

#include <iostream>
#include "Command.hpp"


class Privmsg: public Command
{
	private:

	public:
		Privmsg();
		Privmsg(const Privmsg &copy);
		virtual ~Privmsg();
		Privmsg &operator=(const Privmsg &copy);

		Privmsg(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
