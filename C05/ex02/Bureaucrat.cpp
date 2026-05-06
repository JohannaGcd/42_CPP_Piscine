#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
* *************** Constructors *************** 
*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.name_), grade_(src.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		grade_ = src.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/*
 * *************** Methods: Getters/Setters ***************
 */

const std::string& Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::incrementGrade(int n) {
	if (grade_ - n < 1)
		throw GradeTooHighException();
	else
		grade_ -= n;
}

void Bureaucrat::decrementGrade(int n) {
	if (grade_ + n > 150)
		throw GradeTooLowException();
	else
		grade_ += n;
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.executeAction(*this);
		std::cout << this->name_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}

/*
* *************** Methods: Print *************** 
*/

std::ostream& operator<< (std::ostream& out, const Bureaucrat& src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return out;
}