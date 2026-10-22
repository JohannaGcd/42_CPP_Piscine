#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>

// For this exercise, I highly recommend reading: https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91 

// Merge-Insertion is optimized to make the least number of comparisons
// 1. Pair elements.
// 2. Sort each pair so the smaller comes first.
// 3. Recursively sort the larger elements.
// 4. Insert the smaller elements in Jacobsthal order (a sequence, similar to Fibonacci. The sequence creates balanced sizes, which allows fewer comparisons.)
// 5. Insert the leftover element, if one exists.

// Using a template to print values for all container types
template <typename Container>
static void printValues(const Container& values)
{
	// This creates an iterator suitable for the container type
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
	// std::clock() measures how much CPU time the program has used
	vectorStart = std::clock();
	PmergeMe::sortVectorValues(vectorValues);
	vectorEnd = std::clock();
	dequeStart = std::clock();
	PmergeMe::sortDequeValues(dequeValues);
	dequeEnd = std::clock();
	std::cout << "After: ";
	printValues(vectorValues);
	// Multiplication by 1000000.0 gives time elapsed in microseconds, with decimal precision
	// CLOCKS_PER_SEC is a standard constant which gives how many std::clock() units equal one second
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
