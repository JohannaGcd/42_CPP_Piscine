#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>

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
	std::string::size_type index;

	if (text.empty())
		return false;
	for (index = 0; index < text.size(); ++index)
		if (text[index] < '0' || text[index] > '9')
			return false;
	errno = 0;
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
	for (int index = 1; index < argc; ++index)
	{
		if (!parseNumber(argv[index], value))
			return false;
		values.push_back(value);
		dequeValues.push_back(value);
	}
	return true;
}

void PmergeMe::sortVectorPairs(std::vector<Pair>& pairs)
{
	std::vector<int> larger;
	std::vector<bool> used;
	std::vector<Pair> ordered;
	std::size_t index;

	if (pairs.size() < 2)
		return;
	for (index = 0; index < pairs.size(); ++index)
		larger.push_back(pairs[index].large);
	sortVector(larger);
	used.assign(pairs.size(), false);
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
	pairs.swap(ordered);
}

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

void PmergeMe::makeInsertionOrder(std::vector<int>& order, int count)
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

void PmergeMe::sortVector(std::vector<int>& values)
{
	std::vector<Pair> pairs;
	std::vector<Pair> chain;
	std::vector<int> order;
	std::vector<int> result;
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
	sortVectorPairs(pairs);
	chain.push_back(Pair(pairs[0].large, pairs[0].large, pairs[0].id));
	for (index = 1; index < pairs.size(); ++index)
		chain.push_back(Pair(pairs[index].large, pairs[index].large,
			pairs[index].id));
	insertVector(chain, Pair(pairs[0].small, pairs[0].small, -1), -1);
	makeInsertionOrder(order, static_cast<int>(pairs.size()));
	for (index = 0; index < order.size(); ++index)
		insertVector(chain, pairs[order[index]], pairs[order[index]].id);
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

void PmergeMe::sortVectorValues(std::vector<int>& values)
{
	sortVector(values);
}

void PmergeMe::sortDequeValues(std::deque<int>& values)
{
	sortDeque(values);
}
