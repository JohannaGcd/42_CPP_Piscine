#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printValue(const T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void addOne(T &value)
{
	++value;
}

int	main(void)
{
	int numbers[] = {1, 2, 3, 4};
	const int constNumbers[] = {10, 20, 30};
	std::string words[] = {"alpha", "beta", "gamma"};

	iter(numbers, 4, addOne<int>);
	iter(numbers, 4, printValue<int>);
	iter(constNumbers, 3, printValue<int>);
	iter(words, 3, printValue<std::string>);

	return (0);
}