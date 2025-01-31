#ifndef DATA_HPP
# define DATA_HPP

	#include <vector> //-> for vector

class Data
{
	private:

	public:
		Data();
		Data(const Data &copy);
		virtual ~Data();
		Data &operator=(const Data &copy);

		std::vector<Client> clients;
		std::vector<Channel> channels;
};
#endif
