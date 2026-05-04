#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {
    //Test basic Form creation and getters
    try {
        ShrubberyCreationForm f1("home");

        std::cout << "ShrubberyCreationForm: [145, 137]" << std::endl;
        f1.createFile();
        std::cout << "Grade to sign: " << f1.getGrade_cansign() << std::endl;
        std::cout << "Grade to execute: " << f1.getGrade_canexec() << std::endl;
        std::cout << "Is signed: " << f1.get_is_signed_() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // try {
    //     RobotomyRequestForm f2("home");

    //     std::cout << "RobotomyRequestForm: [72, 45]" << std::endl;

    //     std::cout << "Grade to sign: " << f2.getGrade_cansign() << std::endl;
    //     std::cout << "Grade to execute: " << f2.getGrade_canexec() << std::endl;
    //     std::cout << "Is signed: " << f2.get_is_signed_() << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    //  try {
    //     PresidentialPardonForm f3("home");

    //     std::cout << "PresidentialPardonForm: [25, 5]" << std::endl;
    //     std::cout << "Grade to sign: " << f3.getGrade_cansign() << std::endl;
    //     std::cout << "Grade to execute: " << f3.getGrade_canexec() << std::endl;
    //     std::cout << "Is signed: " << f3.get_is_signed_() << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    return 0;
}

