#ifndef PART_HPP
# define PART_HPP

#include <iostream>
#include "Command.hpp"


class Part : public Command
{
	private:

	public:
		Part();
		Part(const Part &copy);
		virtual ~Part();
		Part &operator=(const Part &copy);

		Part(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
