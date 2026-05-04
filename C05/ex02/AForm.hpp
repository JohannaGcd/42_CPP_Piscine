#ifndef FORM_H
 # define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool is_signed_ = false;
		const int grade_cansign_;
		const int grade_canexec_;

	public:
		AForm(const std::string name, const int grade_cansign, const int grade_canexec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		~AForm();

		std::string getName() const;
		bool get_is_signed_() const; // change to isSigned()
		int getGrade_cansign() const;
		int getGrade_canexec() const;
		void beSigned(Bureaucrat &b);
		void executeForm(Bureaucrat const &executor);

		class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw()
			{
				return "grade is too high";
			}
		};

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw()
			{
				return "grade is too low";
			}
		};
	
	class FormSignatureException: public std::exception {
		public:
			const char *what() const throw() {
				return "Form what not signed";
			}
	};
};

std::ostream &operator<<(std::ostream &out, AForm &src);

#endif