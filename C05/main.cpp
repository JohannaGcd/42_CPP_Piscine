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

// TODO:
// - correct operator<< to write into the stream
// - correct constructor so that it enforces giving a name (name should be const) and delete setName method
// - implement exception block & borders (for increment / decrementing and setting grade!)


// HOW TO THROW CUSTOM EXCEPTIONS:

// #include <iostream>
// #include <exception>

// class TooSmallException : public std::exception {
// public:
//     const char* what() const throw() {
//         return "value is too small";
//     }
// };

// void setValue(int value) {
//     if (value < 10) {
//         throw TooSmallException();
//     }
//     std::cout << "Value accepted: " << value << std::endl;
// }

// int main() {
//     try {
//         setValue(3);
//     }
//     catch (std::exception &e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
// }

// How this works:

// throw interrupts the normal flow and sends an error object upward.
// try marks the code that might fail.
// catch handles the exception.
// what() gives a short error message.