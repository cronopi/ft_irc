#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>

class Channel
{
	private:
		std::string name;
	public:
		Channel();
		Channel(const Channel &copy);
		~Channel();
		Channel &operator=(const Channel  &copy);

		Channel(std::string name);
		std::string	getName();
};
#endif
