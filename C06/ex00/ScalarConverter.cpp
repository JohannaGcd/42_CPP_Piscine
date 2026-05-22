#include "ScalarConverter.hpp"
#include <iostream>

// define enum {
// 	1 = CHAR;
// 	2 = STRING;
// 	3 = INT;
// 	4 = DOUBLE;
// 	5 = FLOAT;

// }

std::string recognize_type(const std::string &str)
{
	if (str.size() == 1 && (str[0] > 0 && str[0] < 127))
		return "char";
	return "other";
}

ScalarConverter::ScalarConverter() {};


// Recognize this is an int literal, parse it to get the number 42, then show what 42 looks like as a char, int, float, and double

void ScalarConverter::convert(const std::string& str) 
{
	std::string type = recognize_type(str);
	std::cout << type << std::endl;
	// convert_to_type (type);
}

