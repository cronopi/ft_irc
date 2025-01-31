#ifndef JOIN_HPP
# define JOIN_HPP

#include <iostream>
#include "Command.hpp"

class Join : Command
{
	private:

	public:
		Join();
		Join(const Join &copy);
		virtual ~Join();
		Join &operator=(const Join &copy);

		Join(Data &data);
		bool Join::handles(std::string command)


};
#endif
