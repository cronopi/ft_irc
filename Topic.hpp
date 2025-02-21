#ifndef TOPIC_HPP
# define TOPIC_HPP

#include <iostream>
#include "Command.hpp"


class Topic : public Command
{
	private:

	public:
		Topic();
		Topic(const Topic &copy);
		virtual ~Topic();
		Topic &operator=(const Topic &copy);

		Topic(Data *data);
		bool handles(std::string command);
		std::string execute(std::string command, size_t i);

};
#endif
