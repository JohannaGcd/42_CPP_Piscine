#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target_(src.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
			AForm::operator=(src);
			target_ = src.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute() const {
	int value = rand();

	std::cout << "[ drilling noise ... ]" << std::endl;

	if (value % 2 == 0)
		std::cout << "Robotomy was successful!" << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return target_;
}