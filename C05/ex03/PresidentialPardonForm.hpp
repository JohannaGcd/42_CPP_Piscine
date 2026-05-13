#ifndef PRESIDENTIAL_FORM_H
 # define PRESIDENTIAL_FORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target_;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		void execute() const override;
		std::string getTarget() const override;
};

#endif
