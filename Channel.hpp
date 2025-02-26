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
		//operator privilage

	public:
		Channel();
		Channel(const Channel &copy);
		Channel(std::string name);

		~Channel();

		Channel &operator=(const Channel  &copy);


		std::string		getName();
		std::string		getTopic();
		unsigned int	getMaxUsers();
		bool			getInviteOnly();
		std::string		getPassword();

		void			setName(std::string name);
		void			setTopic(std::string topic);
		void			setMaxUsers(unsigned int maxUsers);
		void			setInviteOnly(bool inviteOnly);
		void			setPassword(std::string password);

};
#endif
