#include "RPN.hpp"

#include <climits>
#include <cstdlib>
#include <sstream>
#include <stack>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::evaluate(const std::string& expression, long& result)
{
	std::istringstream input(expression);
	std::stack<long> values;
	std::string token;

	while (input >> token)
	{
		if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			values.push(token[0] - '0');
			continue;
		}
		if (token.size() != 1
			|| (token[0] != '+' && token[0] != '-' && token[0] != '*'
				&& token[0] != '/')
			|| values.size() < 2)
			return false;
		long right = values.top();
		values.pop();
		long left = values.top();
		values.pop();
		if (token[0] == '+')
			values.push(left + right);
		else if (token[0] == '-')
			values.push(left - right);
		else if (token[0] == '*')
			values.push(left * right);
		else
		{
			if (right == 0)
				return false;
			values.push(left / right);
		}
	}
	if (values.size() != 1)
		return false;
	result = values.top();
	return true;
}
