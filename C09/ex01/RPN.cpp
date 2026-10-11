#include "RPN.hpp"

#include <climits>
#include <cstdlib>
#include <sstream>
#include <stack>

RPN::RPN()
{
}

// other is required by the OCF, but RPN has no member data to copy
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
	// Lets you read and parse data from a string as if you were reading from the standard input;
	// Splits tokens based on spaces, tabs, or newlines
	std::istringstream input(expression);
	std::stack<long> values;
	std::string token;

	while (input >> token)
	{
		// 1. Create the stack
		// 1.a Check if we have a valid operand
		if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			values.push(token[0] - '0');
			continue;
		}
		// 1.b Check if we have a valid operator
		if (token.size() != 1
			|| (token[0] != '+' && token[0] != '-' && token[0] != '*'
				&& token[0] != '/')
			|| values.size() < 2)
			return false;

		// 2. Pop the last two values
		long right = values.top();
		values.pop();
		long left = values.top();
		values.pop();

		// 3. Evaluate the expression between left & right, then push it to the stack
		if (token[0] == '+')
			values.push(left + right);
		else if (token[0] == '-')
			values.push(left - right);
		else if (token[0] == '*')
			values.push(left * right);
		else
		{
			if (right == 0) // Check for invalid division by 0
				return false;
			values.push(left / right);
		}
	}
	// 4. There should be no more than 1 value left in the stack.
	if (values.size() != 1)
		return false;
	result = values.top();
	return true;
}
