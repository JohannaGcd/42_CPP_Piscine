#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>

ScalarConverter::ScalarConverter() {};

std::string recognize_type(const std::string& str) {
  if (str.empty()) return "other";
  if (str.size() == 1 &&
      ((str[0] > 0 && str[0] < 48) || (str[0] > 57 && str[0] < 127)))
    return ("char");
  else if ((str.find('.') != std::string::npos) &&
           (str.find('f') != std::string::npos))
    return ("float");
  else if ((str.find('.') != std::string::npos) &&
           (str.find('f') == std::string::npos))
    return ("double");
  else if (str == "nan" || str == "nanf" || str == "-inff" | str == "+inff" ||
           str == "-inf" || str == "+inf")
    return "pseudo-literal";
  return "int";
}

template <typename T>

void print_conversions(T value) {
  std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(value) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(value) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(value) << std::endl;
}

void print_conversions_char(char value) {
  std::cout << "char: " << value << std::endl;
  std::cout << "int: " << static_cast<int>(value) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(value) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(value) << std::endl;
}

void print_conversions_pseudoLiterals(std::string value) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << value << "f" << std::endl;
  std::cout << "double: " << value << std::endl;
}

bool confirm_int_type(std::string input) {
  int size = input.size();
  for (int i = 0; i < size; i++) {
    if (input[i] < 48 || input[i] > 57) return false;
  }
  return true;
}
// Recognize this is an int literal, parse it to get the number 42,
//	then show what 42 looks like as a char, int, float, and double
void ScalarConverter::convert(const std::string& str) {
  std::string type = recognize_type(str);
  if (confirm_int_type(str) == false) {
    std::cout << "Error: Invalid input" << std::endl;
    return;
  }

  try {
    if (type == "int") {
      int value = stoi(str);
      print_conversions(value);
    } else if (type == "float") {
      float value = stof(str);
      print_conversions(value);
    } else if (type == "double") {
      double value = stod(str);
      print_conversions(value);
    } else if (type == "char") {
      char value = str[0];
      print_conversions_char(value);
    } else if (type == "pseudo-literal") {
      print_conversions_pseudoLiterals(str);
    }
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}
