#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};

// Intern::Intern(const Intern &src) {};

// Intern& Intern::operator=(const Intern &src) {
// 	return *this;
// }

AForm* Intern::makeForm(std::string name, std::string target) {

	try {
		if (name.find("robotomy"))
			return new RobotomyRequestForm(target);
		else if (name.find("presidential"))
			return new PresidentialPardonForm(target);
		else if (name.find("shrubbery"))
			return new ShrubberyCreationForm(target);
		else
			std::cout << "Wrong name" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error : " << std::endl;
	}
	return NULL;
}
