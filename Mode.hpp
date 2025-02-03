#ifndef MODE_HPP
# define MODE_HPP

#include <iostream>
#include "Command.hpp"

class Mode : public Command
{
	private:

	public:
		Mode();
		Mode(const Mode &copy);
		virtual ~Mode();
		Mode &operator=(const Mode &copy);

		Mode(Data &data);
		bool handles(std::string command);
		std::string execute(std::string command, std::string clientName);

};
#endif
