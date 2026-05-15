#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {
    try {
        Intern I;
        AForm* f1;
        f1 = I.makeForm("robotomy ret", "Bender");
        std::cout << f1->getName() << std::endl;
       // std::cout << f1->getTarget() << std::endl;
               //delete (f1);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;


    return 0;
}

