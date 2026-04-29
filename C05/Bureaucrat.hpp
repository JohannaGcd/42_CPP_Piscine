#ifndef BUREAUCRAT_H
 # define BUREAUCRAT_H

#include <string>

class Bureaucrat {
	private:
		const std::string name_;
		int grade_;

	public:
		const std::string getName();
		const std::string getGrade();
		void incrementGrade(int n);
		void decrementGrade(int n);
		void GradeTooHighException();
		void GradeTooLowException();
		vpo
}

#endif