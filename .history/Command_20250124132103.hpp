#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>

class Command
{
	private:
		Data data;

	public:
		Command();
		Command(const Command &copy);
		virtual ~Command();
		Command &operator=(const Command &copy);

		Command(Data data);
		virtual bool handles(std::string Command) = 0;
		virtual void execute(std::string Command) = 0;

};
#endif
