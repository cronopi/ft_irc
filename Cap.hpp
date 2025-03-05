#ifndef CAP_HPP
# define CAP_HPP

#include <iostream>
#include "Command.hpp"

class Cap : public Command
{
	private:

	public:
		Cap();
		Cap(const Cap &copy);
		virtual ~Cap();
		Cap &operator=(const Cap &copy);

		Cap(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
