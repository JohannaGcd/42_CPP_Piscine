#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	BitcoinExchange exchange;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (!exchange.loadInput(argv[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	return 0;
}
