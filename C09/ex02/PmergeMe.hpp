#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
private:
	// This is a nested struct type. 
	// It is used inside the class, by the sorting function, but it is not a member attribute of the class.
	struct Pair
	{
		int small;
		int large;
		int id;
		Pair(int small, int large, int id);
	};

	static bool parseNumber(const std::string& text, int& value);
	static void sortVector(std::vector<int>& values);
	static void sortDeque(std::deque<int>& values);
	static void sortVectorPairs(std::vector<Pair>& pairs);
	static void sortDequePairs(std::deque<Pair>& pairs);
	static void insertVector(std::vector<Pair>& chain, const Pair& item,
		int bound);
	static void insertDeque(std::deque<Pair>& chain, const Pair& item,
		int bound);
	static void makeInsertionOrder(std::vector<int>& order, int count);
	static void makeInsertionOrder(std::deque<int>& order, int count);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	static bool parseArguments(int argc, char** argv,
		std::vector<int>& values, std::deque<int>& dequeValues);
	// vectors use contiguous memory
	// deque avoids large reallocation while growing
	// this exercice compares their performance
	static void sortVectorValues(std::vector<int>& values);
	static void sortDequeValues(std::deque<int>& values);
};

#endif
