#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	// Creating a Bureaucrat with each constructor
	Bureaucrat A;
	A.setName("Alice");
	std::cout << "A name should be Alice: " << A.getName() << std::endl;
	std::cout << std::endl;

	Bureaucrat B(A);
	std::cout << "B name should be Alice: " << B.getName() << std::endl;
	B.setName("Bob");
	std::cout << "B name should now be Bob: " << B.getName() << std::endl;
	std::cout << std::endl;

	Bureaucrat C;
	C = B;
	std::cout << "C name should be Bob: " << C.getName() << std::endl;
	C.setName("Corinne");
	std::cout << "C name should be Corinne: " << C.getName() << std::endl;
	std::cout << std::endl;

	// Testing each method and contructor
	std::cout << "get A grade before setting it, should be 1 (default value): " << A.getGrade() << std::endl;
	A.setGrade(50);
	std::cout << "set A grade to 50: " << A.getGrade() << std::endl;
}