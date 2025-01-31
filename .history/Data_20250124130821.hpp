#ifndef DATA_HPP
# define DATA_HPP

#include <vector> //-> for vector

class Data
{
	private:
		std::vector<Client> clients;
		std::vector<Channel> channels;

	public:
		Data();
		Data(const Data &copy);
		virtual ~Data();
		Data &operator=(const Data &copy);

};
#endif
