#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
private:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

public:
	static bool evaluate(const std::string& expression, long& result);
};

#endif
