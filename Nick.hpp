#ifndef NICK_HPP
# define NICK_HPP

#include <iostream>
#include "Command.hpp"


class Nick : public Command
{
	private:

	public:
		Nick();
		Nick(const Nick &copy);
		virtual ~Nick();
		Nick &operator=(const Nick &copy);

		Nick(Data &data);
		bool handles(std::string command);
		std::string execute(std::string command, std::string clientName);

};
#endif
