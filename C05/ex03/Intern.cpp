#include "Intern.hpp"

#include <functional>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};

AForm *Intern::makeForm(std::string name, std::string target) {
  struct Form {
    std::string name;
    std::function<AForm *(const std::string &)> allocator;
  };

  Form forms[] = {{"shrubbery creation",
                   [](const std::string &target) {
                     return (new ShrubberyCreationForm(target));
                   }},
                  {"robotomy request",
                   [](const std::string &target) {
                     return (new RobotomyRequestForm(target));
                   }},
                  {"presidential pardon", [](const std::string &target) {
                     return (new PresidentialPardonForm(target));
                   }}};

  for (const Form &form : forms) {
    if (form.name == name) {
      std::cout << "Intern creates " << name << std::endl;
      return (form.allocator(target));
    }
  }
  std::cerr << "form name: \'" << name << "\' not recognized." << std::endl;
  return (nullptr);
}
