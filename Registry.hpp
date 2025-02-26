#ifndef REGISTRY_HPP
# define REGISTRY_HPP

#include <iostream>
#include "Command.hpp"

class Registry
{
	private:
		std::string usersDatabase;

	public:
		Registry();
		Registry(const Registry &copy);
		virtual ~Registry();
		Registry &operator=(const Registry &copy);

		bool authenticateUser(std::string user, std::string password);
		bool registerUser(std::string newUser, std::string password, std::string nickname);
		void changePassword(std::string user, std::string newPass);

		std::string readNick(std::string user);
};
#endif
