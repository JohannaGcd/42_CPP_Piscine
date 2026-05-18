#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <array>

int main(void) {
    try {
        Intern I;
        Bureaucrat bu("Emeric", 1);

        std::cout << "Create valid forms, sign and execute." << std::endl;

        std::array<std::string, 3> formNames = { "shrubbery creation", "robotomy request", "presidential pardon"};

        for (const auto& formName : formNames) {
            AForm *tr = I.makeForm(formName, "<test>");
            if (!tr)
                break;
        
            std::cout << tr << std::endl;
            bu.signForm(*tr);
            bu.executeForm(*tr);
            delete (tr);
            std::cout << std::endl;
        }

        std::cout << "Create Invalid form." << std::endl;

        AForm* ptr = I.makeForm("wrong name", "test");
        if (ptr == nullptr)
            std::cout << "allocation error" << std::endl;

    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

