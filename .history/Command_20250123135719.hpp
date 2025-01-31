#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "Server.hpp"

class Command
{
	private:


	public:
		Command();
		Command(const Command &copy);
		virtual ~Command();
		Command &operator=(const Command &copy);

		virtual bool handles(std::string Command) = 0;
		virtual void execute(std::string Command) = 0;

};
#endif
