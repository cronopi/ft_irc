#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>

class Channel
{
	private:
		std::string		name;
		std::string		topic;
		bool			inviteOnly;
		bool			topicRestricted;
		std::string		Password;
		unsigned int	maxUsers;

	public:
		Channel();
		Channel(const Channel &copy);
		~Channel();
		Channel &operator=(const Channel  &copy);

		Channel(std::string name);
		std::string	getName();
		std::string	getTopic();
		std::string	getMaxUsers();

		std::string	setName(std::string name);
		std::string	setTopic(std::string topic);
		std::string	setMaxUsers(unsigned int maxUsers);
};
#endif
