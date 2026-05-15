#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    std::cout << "[ TEST = Creating a Bureaucrat with each constructor ]" << std::endl;
    Bureaucrat A("Alice", 50);
    std::cout << "--A name should be Alice with a grade of 0--" << std::endl;
    std::cout << A;
    std::cout << std::endl;

    Bureaucrat B(A);
    std::cout << "--B name should be Alice, with a grade of 0--" << std::endl;
    std::cout << B;
    std::cout << std::endl;

	try {
		std::cout << "--Trying to instantiate Corinne, with a grade of 0. Should fail--" << std::endl;
    	Bureaucrat C("Corinne", 0);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "[ TEST = Setting grades, and testing exceptions ]" << std::endl;
    std::cout << std::endl;

    std::cout << "The following test sets A's grade to 0. Should KO." << std::endl;
    try {
        A.incrementGrade(50);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "The following test sets A's grade to 151. Should KO." << std::endl;
    try {
        A.decrementGrade(101);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
