#ifndef MSG_HPP
# define MSG_HPP

#include <iostream>
#include "Command.hpp"

class Msg : public Command
{
	private:

	public:
		Msg();
		Msg(const Msg &copy);
		virtual ~Msg();
		Msg &operator=(const Msg &copy);

		Msg(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
