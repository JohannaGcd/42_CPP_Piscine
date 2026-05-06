#ifndef ROBOTOMY_FORM_H
 # define ROBOTOMY_FORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target_;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		void execute() const override;
};

#endif