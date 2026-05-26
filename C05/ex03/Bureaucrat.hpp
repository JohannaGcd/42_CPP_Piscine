#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;

 public:
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat& src);
  Bureaucrat& operator=(const Bureaucrat& src);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;
  void incrementGrade(unsigned int n);
  void decrementGrade(unsigned int n);
  void executeForm(AForm const& form) const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const noexcept { return "grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const noexcept { return "grade is too low"; }
  };

  void signForm(AForm& f);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif