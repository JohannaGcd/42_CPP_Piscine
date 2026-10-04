#include "RPN.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	long result;

	if (argc != 2 || !RPN::evaluate(argv[1], result))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << result << std::endl;
	return 0;
}
