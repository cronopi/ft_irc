#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>
#include "Data.hpp"

class Command
{
	private:

	protected:
		Data data;

	public:
		Command();
		Command(const Command &copy);
		virtual ~Command() = default;
		Command &operator=(const Command &copy);

		Command(Data &data);
		virtual bool handles(std::string command) = 0;
		virtual void execute(std::string command) = 0;

};
#endif
