// main.cpp

#include "Join.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    Join join(data);
	bool result;

	result = join.handles("JOIN canal_1");


    return 0;
}
