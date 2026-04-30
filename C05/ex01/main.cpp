#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    // Test basic Form creation and getters
    try {
        Form f1("Form A", 50, 25);
        std::cout << f1;
        // std::cout << "Grade to sign: " << f1.getGrade_cansign() << std::endl;
        // std::cout << "Grade to execute: " << f1.getGrade_canexec() << std::endl;
        // std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;

        // Test beSigned with eligible Bureaucrat
        Bureaucrat b1("Alice", 50);
        std::cout << b1;
        f1.beSigned(b1);
        std::cout << "Form signed by " << b1.getName() << std::endl;
        std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test beSigned with ineligible Bureaucrat
    try {
        Bureaucrat b2("Bob", 100);
        std::cout << b2;
        std::cout << std::endl;

        Form f2("Form B", 50, 25);
        std::cout << f2;

        f2.beSigned(b2);
    } catch (std::exception& e) {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    // Test GradeTooHighException
    try {
        Form f3("Form C", 0, 25);
    } catch (Form::GradeTooHighException &e) {
        std::cout << "GradeTooHighException: " << e.what() << std::endl;
    }
    
    // Test GradeTooLowException
    try {
        Form f4("Form D", 151, 25);
    } catch (Form::GradeTooLowException &e) {
        std::cout << "GradeTooLowException: " << e.what() << std::endl;
    }
    
    return 0;
}
