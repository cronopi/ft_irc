// main.cpp

#include "Join.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    Join join(data);
	bool result;

	result = join.handles("JOhn canal_1");

	std::cout << "Result: " << result << std::endl;
    return 0;
}
