
#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include "Command.hpp"

class User : public Command
{
	private:

	public:
		User();
		User(const User &copy);
		virtual ~User();
		User &operator=(const User &copy);

		User(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
