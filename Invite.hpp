#ifndef INVITE_HPP
# define INVITE_HPP

#include <iostream>
#include "Command.hpp"

class Invite : public Command
{
	private:

	public:
		Invite();
		Invite(const Invite &copy);
		virtual ~Invite();
		Invite &operator=(const Invite &copy);

		Invite(Data &data);
		bool handles(std::string command);
		std::string execute(std::string command, std::string clientName);

};
#endif
