#ifndef SHRUBBERY_FORM_H
 # define SHRUBBERY_FORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target_;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		void execute() const override;
		std::string getTarget() const override;
};

#endif
