
#ifndef REGISTER_HPP
# define REGISTER_HPP

#include <iostream>
#include "Command.hpp"

class Register : public Command
{
	private:

	public:
		Register();
		Register(const Register &copy);
		virtual ~Register();
		Register &operator=(const Register &copy);

		Register(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
