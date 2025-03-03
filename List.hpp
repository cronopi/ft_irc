#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "Command.hpp"

class List : public Command
{
	private:

	public:
		List();
		List(const List &copy);
		virtual ~List();
		List &operator=(const List &copy);

		List(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
