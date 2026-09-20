#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void testEasyfind(const T& container, int value)
{
	try
	{
		typename T::const_iterator it = easyfind(container, value);
		std::cout << "Found " << value << " at " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
    // vectors store values contiguously in memory
	std::vector<int> vectorContainer;
	vectorContainer.push_back(10);
	vectorContainer.push_back(20);
	vectorContainer.push_back(30);

    // lists store values in a linked manner
	std::list<int> listContainer;
	listContainer.push_back(1);
	listContainer.push_back(2);
	listContainer.push_back(3);

    // deque is a dynamic array that can grow on both ends
	std::deque<int> dequeContainer;
	dequeContainer.push_back(5);
	dequeContainer.push_back(6);
	dequeContainer.push_back(7);

	testEasyfind(vectorContainer, 20);
	testEasyfind(vectorContainer, 99);
	testEasyfind(listContainer, 2);
	testEasyfind(listContainer, 42);
	testEasyfind(dequeContainer, 7);
	testEasyfind(dequeContainer, -1);

	return 0;
}