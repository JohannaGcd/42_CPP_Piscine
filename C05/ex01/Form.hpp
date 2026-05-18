#ifndef FORM_H
 # define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name_;
	bool is_signed_ = false;
	const int grade_cansign_;
	const int grade_canexec_;

public:
	Form(const std::string name, const int grade_cansign, const int grade_canexec);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	std::string getName() const;
	bool get_is_signed_() const;
	int getGrade_cansign() const;
	int getGrade_canexec() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const noexcept 
		{
			return "grade is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept
		{
			return "grade is too low";
		}
	};

	void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, Form &src);

#endif