#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {
    try {
        ShrubberyCreationForm f1("home");
        Bureaucrat b1("Bob", 50);

        std::cout << " [ TEST - SHOULD PASS ]" << std::endl;
        std::cout << "ShrubberyCreationForm: [145, 137]" << std::endl;
        std::cout << "Grade to sign: " << f1.getGrade_cansign() << std::endl;
        std::cout << "Grade to execute: " << f1.getGrade_canexec() << std::endl;
        std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        RobotomyRequestForm f2("home");
        Bureaucrat b2("Bea", 120);

        std::cout << " [ TEST - SHOULD FAIL ]" << std::endl;
        std::cout << "RobotomyRequestForm: [72, 45]" << std::endl;
        std::cout << "Grade to sign: " << f2.getGrade_cansign() << std::endl;
        std::cout << "Grade to execute: " << f2.getGrade_canexec() << std::endl;
        std::cout << "Is signed: " << f2.get_is_signed_() << std::endl;
        b2.signForm(f2);
        b2.executeForm(f2);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        PresidentialPardonForm f3("home");
        Bureaucrat b3("Benj", 4);

        std::cout << " [ TEST - SHOULD PASS ]" << std::endl;
        std::cout << "PresidentialPardonForm: [25, 5]" << std::endl;
        std::cout << "Grade to sign: " << f3.getGrade_cansign() << std::endl;
        std::cout << "Grade to execute: " << f3.getGrade_canexec() << std::endl;
        std::cout << "Is signed: " << f3.get_is_signed_() << std::endl;
        b3.signForm(f3);
        b3.executeForm(f3);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

