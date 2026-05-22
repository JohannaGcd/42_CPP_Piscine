#include "ScalarConverter.hpp"
#include <iostream>

int main(void) {
  std::string input;
  std::cout << "Input: " << std::endl;
  std::cin >> input;
  ScalarConverter::convert(input);
}