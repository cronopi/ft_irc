#ifndef JOIN_HPP
# define JOIN_HPP

#include <iostream>
#include "Command.hpp"

class Join : public Command
{
	private:

	public:
		Join();
		Join(const Join &copy);
		virtual ~Join();
		Join &operator=(const Join &copy);

		Join(Data &data);
		bool handles(std::string command);
		std::string execute(std::string command, std::string clientName);

};
#endif
