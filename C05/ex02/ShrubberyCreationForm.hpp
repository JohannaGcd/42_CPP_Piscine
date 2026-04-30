#ifndef SHRUBBERY_FORM_H
 # define SHRUBEERY_FORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
	public:
		ShrubberyCreationForm(const std::string name_, const int grade_cansign, const int grade_canexec);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
};

#endif