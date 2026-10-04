#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>

template <typename Container>
static void printValues(const Container& values)
{
	typename Container::const_iterator it = values.begin();
	while (it != values.end())
	{
		std::cout << *it;
		++it;
		if (it != values.end())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	std::vector<int> vectorValues;
	std::deque<int> dequeValues;
	std::clock_t vectorStart;
	std::clock_t dequeStart;
	std::clock_t vectorEnd;
	std::clock_t dequeEnd;

	if (!PmergeMe::parseArguments(argc, argv, vectorValues, dequeValues))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << "Before: ";
	printValues(vectorValues);
	vectorStart = std::clock();
	PmergeMe::sortVectorValues(vectorValues);
	vectorEnd = std::clock();
	dequeStart = std::clock();
	PmergeMe::sortDequeValues(dequeValues);
	dequeEnd = std::clock();
	std::cout << "After: ";
	printValues(vectorValues);
	std::cout << "Time to process a range of " << vectorValues.size()
		<< " elements with std::vector : "
		<< 1000000.0 * (vectorEnd - vectorStart) / CLOCKS_PER_SEC
		<< " us" << std::endl;
	std::cout << "Time to process a range of " << dequeValues.size()
		<< " elements with std::deque : "
		<< 1000000.0 * (dequeEnd - dequeStart) / CLOCKS_PER_SEC
		<< " us" << std::endl;
	return 0;
}
