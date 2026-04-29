#include "Bureaucrat.hpp"
#include <iostream>

/*
* *************** Constructors *************** 
*/

Bureaucrat::Bureaucrat() : name_("default"), grade_(0) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.name_), grade_(src.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		name_ = src.name_;
		grade_ = src.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/*
 * *************** Methods: Getters/Setters ***************
 */

std::string Bureaucrat::getName() {
	return name_;
}

int Bureaucrat::getGrade() {
	return grade_;
}

void Bureaucrat::setName(std::string name) {
	name_ = name;
}

void Bureaucrat::setGrade(int n) {
	grade_ = n;
}

void Bureaucrat::incrementGrade(int n) {
	grade_ -= n;
}

void Bureaucrat::decrementGrade(int n) {
	grade_ += n;
}

/*
* *************** Methods: Throw Exceptions *************** 
*/

// void Bureaucrat::GradeTooHighException();
// void Bureaucrat::GradeTooLowException();

/*
* *************** Methods: Print *************** 
*/

void Bureaucrat::operator<< (const Bureaucrat& src) const {
	std::cout << src.name_ << ", bureaucrat grade " << src.grade_ << std::endl;
}