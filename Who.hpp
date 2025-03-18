#ifndef WHO_HPP
# define WHO_HPP

#include <iostream>
#include "Command.hpp"

class Who : public Command
{
	private:

	public:
		Who();
		Who(const Who &copy);
		virtual ~Who();
		Who &operator=(const Who &copy);

		Who(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
