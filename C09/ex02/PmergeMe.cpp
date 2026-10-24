#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>

// Constructor for the nested type, Pair struct
PmergeMe::Pair::Pair(int smallValue, int largeValue, int identifier)
	: small(smallValue), large(largeValue), id(identifier)
{
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::parseNumber(const std::string& text, int& value)
{
	char* end = 0;
	long parsed;
	std::string::size_type index; // type used by std::string for sizes and indexes

	if (text.empty())
		return false;
	for (index = 0; index < text.size(); ++index)
		if (text[index] < '0' || text[index] > '9')
			return false;
	errno = 0;
	// strtol takes a c_string, returns a ptr to the end of the number, works with decimal and other bases (binary etc)
	parsed = std::strtol(text.c_str(), &end, 10);
	if (errno == ERANGE || end == text.c_str() || *end != '\0'
		|| parsed <= 0 || parsed > INT_MAX)
		return false;
	value = static_cast<int>(parsed);
	return true;
}

bool PmergeMe::parseArguments(int argc, char** argv,
	std::vector<int>& values, std::deque<int>& dequeValues)
{
	int value;

	if (argc < 2)
		return false;
	for (int index = 1; index < argc; ++index) // pre-increment avoids creating a temp copy
	{
		if (!parseNumber(argv[index], value))
			return false;
		values.push_back(value);
		dequeValues.push_back(value);
	}
	return true;
}

// sortVector() receives the original values
// It extracts the larger values from each pair
// It calls itself with the vector with the larger values
// Call repeats until the vector contains fewer than two values
// Then the function calls finish one by one, using the sorted larger values to rebuild the complete sorted sequence.
void PmergeMe::sortVectorPairs(std::vector<Pair>& pairs)
{
	std::vector<int> larger;
	std::vector<bool> used;
	// declares an empty vector whose elements are Pair objects
	// used to stored the pairs in their sorted order after sorting the larger values.
	std::vector<Pair> ordered; 
	std::size_t index;

	if (pairs.size() < 2)
		return;
	// copy the larger values from every pair into the larger vector
	for (index = 0; index < pairs.size(); ++index)
		larger.push_back(pairs[index].large);
	// recursive call with the larger values
	sortVector(larger);
	// assigns a bool false to each original pair	
	used.assign(pairs.size(), false);
	// rebuilds the pairs in the same order as the sorted larger values
	for (index = 0; index < larger.size(); ++index)
	{
		std::size_t candidate;
		for (candidate = 0; candidate < pairs.size(); ++candidate)
		{
			if (!used[candidate] && pairs[candidate].large == larger[index])
			{
				ordered.push_back(pairs[candidate]);
				used[candidate] = true;
				break;
			}
		}
	}
	// exchanges the contents of the two vectors
	pairs.swap(ordered);
}

// Inserts one Pair into the correct position, in the sorted chain
// 1. receives the current chain, the item pair to insert and bound.
// bound is used to find the corresponding larger value already in the chain
// 2. starts from the beginning of the chain, find the upper limit at bound
// 3. then traverse from the start again, finding the closest smaller value
// 4. insert the item pair at that position.
void PmergeMe::insertVector(std::vector<Pair>& chain, const Pair& item,
	int bound)
{
	std::vector<Pair>::iterator limit = chain.end();
	std::vector<Pair>::iterator it;
	
	if (bound >= 0)
	{
		for (it = chain.begin(); it != chain.end(); ++it)
			if (it->id == bound)
			{
				limit = it;
				break;
			}
	}
	it = chain.begin();
	while (it != limit && it->small <= item.small)
		++it;
	chain.insert(it, item);
}
/* Creates the order in which the smaller values from the pairs will be inserted.
Larger values have already been sorted, so there are used as an "upper limit", to reduce the amount of comparisons needed for sorting.
*/ 
void PmergeMe::makeInsertionOrder(std::vector<int>& order, int count)
{
	// defines group boundaries
	// ex: 1, current 3 -> indexes 2, 1
	int previous = 1;
	int current = 3;

	while (previous < count)
	{
		if (current > count)
			current = count;
		for (int index = current - 1; index >= previous; --index)
			order.push_back(index);
		previous = current;
		// follows a fixed jacobstahl sequence blueprint
		current = 2 * previous + 1;
	}
}

void PmergeMe::sortVector(std::vector<int>& values)
{
	std::vector<Pair> pairs;
	std::vector<Pair> chain;
	std::vector<int> order;
	std::vector<int> result;
	std::size_t index;
	int id = 0;
	bool hasOdd = values.size() % 2 == 1;
	int odd = hasOdd ? values.back() : 0; // if hasOdd, save the last value

	if (values.size() < 2)
		return;
	for (index = 0; index + 1 < values.size(); index += 2)
	{
		// building the pairs
		// insert smaller values first, & give the pair an id
		if (values[index] <= values[index + 1])
			pairs.push_back(Pair(values[index], values[index + 1], id++));
		else
			pairs.push_back(Pair(values[index + 1], values[index], id++));
	}
	sortVectorPairs(pairs); // sorts pairs by larger values
	chain.push_back(Pair(pairs[0].large, pairs[0].large, pairs[0].id)); // insert only the larger values in chain
	for (index = 1; index < pairs.size(); ++index)
		chain.push_back(Pair(pairs[index].large, pairs[index].large,
			pairs[index].id));
	insertVector(chain, Pair(pairs[0].small, pairs[0].small, -1), -1); // insert first smaller values
	makeInsertionOrder(order, static_cast<int>(pairs.size())); // create the order for the remaining smaller values
	for (index = 0; index < order.size(); ++index)
		insertVector(chain, pairs[order[index]], pairs[order[index]].id); // insert those values remaining according to order
	if (hasOdd)
		insertVector(chain, Pair(odd, odd, -1), -1);
	for (index = 0; index < chain.size(); ++index)
		result.push_back(chain[index].small);
	values.swap(result);
}

void PmergeMe::sortDequePairs(std::deque<Pair>& pairs)
{
	std::deque<int> larger;
	std::deque<bool> used;
	std::deque<Pair> ordered;
	std::size_t index;

	if (pairs.size() < 2)
		return;
	for (index = 0; index < pairs.size(); ++index)
		larger.push_back(pairs[index].large);
	sortDeque(larger);
	used.assign(pairs.size(), false);
	for (index = 0; index < larger.size(); ++index)
	{
		std::size_t candidate;
		for (candidate = 0; candidate < pairs.size(); ++candidate)
			if (!used[candidate] && pairs[candidate].large == larger[index])
			{
				ordered.push_back(pairs[candidate]);
				used[candidate] = true;
				break;
			}
	}
	pairs.swap(ordered);
}

void PmergeMe::insertDeque(std::deque<Pair>& chain, const Pair& item, int bound)
{
	std::deque<Pair>::iterator limit = chain.end();
	std::deque<Pair>::iterator it;

	if (bound >= 0)
		for (it = chain.begin(); it != chain.end(); ++it)
			if (it->id == bound)
			{
				limit = it;
				break;
			}
	it = chain.begin();
	while (it != limit && it->small <= item.small)
		++it;
	chain.insert(it, item);
}

void PmergeMe::makeInsertionOrder(std::deque<int>& order, int count)
{
	int previous = 1;
	int current = 3;

	while (previous < count)
	{
		if (current > count)
			current = count;
		for (int index = current - 1; index >= previous; --index)
			order.push_back(index);
		previous = current;
		current = 2 * previous + 1;
	}
}

void PmergeMe::sortDeque(std::deque<int>& values)
{
	std::deque<Pair> pairs;
	std::deque<Pair> chain;
	std::deque<int> order;
	std::deque<int> result;
	std::size_t index;
	int id = 0;
	bool hasOdd = values.size() % 2 == 1;
	int odd = hasOdd ? values.back() : 0;

	if (values.size() < 2)
		return;
	for (index = 0; index + 1 < values.size(); index += 2)
	{
		if (values[index] <= values[index + 1])
			pairs.push_back(Pair(values[index], values[index + 1], id++));
		else
			pairs.push_back(Pair(values[index + 1], values[index], id++));
	}
	sortDequePairs(pairs);
	chain.push_back(Pair(pairs[0].large, pairs[0].large, pairs[0].id));
	for (index = 1; index < pairs.size(); ++index)
		chain.push_back(Pair(pairs[index].large, pairs[index].large,
			pairs[index].id));
	insertDeque(chain, Pair(pairs[0].small, pairs[0].small, -1), -1);
	makeInsertionOrder(order, static_cast<int>(pairs.size()));
	for (index = 0; index < order.size(); ++index)
		insertDeque(chain, pairs[order[index]], pairs[order[index]].id);
	if (hasOdd)
		insertDeque(chain, Pair(odd, odd, -1), -1);
	for (index = 0; index < chain.size(); ++index)
		result.push_back(chain[index].small);
	values.swap(result);
}


/* Overall sorting logic:
1. Group input values into pairs and store each as (small, large).
2. Sort the pairs according to their large values.
3. Put all large values into the initial chain
4. Insert the first pair's small value into the chain
5. Create the insertion order for the remaining pair indexes.
6. Insert the remaining small values according to that order.
7. If there was an unpaired odd value, insert it into the chain.
8. Copy the sorted values from chain into the result container.
*/
void PmergeMe::sortVectorValues(std::vector<int>& values)
{
	sortVector(values);
}

void PmergeMe::sortDequeValues(std::deque<int>& values)
{
	sortDeque(values);
}
