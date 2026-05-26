#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern &src);
  Intern &operator=(const Intern &src);

  AForm *makeForm(std::string name, std::string target);
};

#endif