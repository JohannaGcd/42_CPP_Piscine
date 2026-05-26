#include "Bureaucrat.hpp"

/*
 * *************** Constructors ***************
 */

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : name_(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name_(src.name_), grade_(src.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
    grade_ = src.grade_;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

/*
 * *************** Methods: Getters/Setters ***************
 */

const std::string& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade(unsigned int n) {
  if (grade_ - n < 1)
    throw GradeTooHighException();
  else
    grade_ -= n;
}

void Bureaucrat::decrementGrade(unsigned int n) {
  if (grade_ + n > 150)
    throw GradeTooLowException();
  else
    grade_ += n;
}

/*
 * *************** Methods: Print ***************
 */

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
  out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
  return out;
}