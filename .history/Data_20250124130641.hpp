#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:


	public:
		Data();
		Data(const Data &copy);
		virtual ~Data();
		Data &operator=(const Data &copy);

};
#endif
