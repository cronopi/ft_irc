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
		virtual ~Command();
		Command &operator=(const Command &copy);

		Command(Data &data);
		virtual bool handles(std::string command) = 0;
		virtual std::string execute(std::string command, std::string ChannelName) = 0;
};
#endif
