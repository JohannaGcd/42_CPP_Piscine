#ifndef BUREAUCRAT_H
 # define BUREAUCRAT_H

#include <string>

class Bureaucrat {
	private:
		std::string name_;
		int grade_;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade_);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		const std::string& getName() const ;
		void setName(std::string name);
		int getGrade() const;
		void setGrade(int n);
		void incrementGrade(int n);
		void decrementGrade(int n);
		void GradeTooHighException();
		void GradeTooLowException();
		void operator<< (const Bureaucrat& src) const;
};

#endif