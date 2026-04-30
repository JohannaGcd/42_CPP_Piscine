#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    try {
        // Test basic Form creation and getters
        Form f1("Form A", 50, 25);
        std::cout << "Form created: " << f1.getName() << std::endl;
        std::cout << "Grade to sign: " << f1.getGrade_cansign() << std::endl;
        std::cout << "Grade to execute: " << f1.getGrade_canexec() << std::endl;
        std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;
        
        // Test beSigned with eligible Bureaucrat
        Bureaucrat b1("Alice", 40);
        f1.beSigned(b1);
        std::cout << "Form signed by " << b1.getName() << std::endl;
        std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;
        
        // Test beSigned with ineligible Bureaucrat
        Bureaucrat b2("Bob", 100);
        Form f2("Form B", 50, 25);
        f2.beSigned(b2);
        
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test GradeTooHighException
    try {
        Form f3("Form C", 0, 25);
    } catch (Form::GradeTooHighException &e) {
        std::cerr << "GradeTooHighException: " << e.what() << std::endl;
    }
    
    // Test GradeTooLowException
    try {
        Form f4("Form D", 151, 25);
    } catch (Form::GradeTooLowException &e) {
        std::cerr << "GradeTooLowException: " << e.what() << std::endl;
    }
    
    return 0;
}
