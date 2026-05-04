#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int grade_cansign, const int grade_canexec) : name_(name), grade_cansign_(grade_cansign), grade_canexec_(grade_canexec) {
	if (grade_cansign < 1 || grade_canexec < 1 )
		throw GradeTooHighException();
	if (grade_cansign > 150 || grade_canexec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : name_(src.name_), is_signed_(src.is_signed_), grade_cansign_(src.grade_cansign_), grade_canexec_(src.grade_canexec_) {}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		is_signed_ = src.is_signed_;
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return name_;
}

bool AForm::get_is_signed_() const {
	return is_signed_;
}

int AForm::getGrade_cansign() const {
	return grade_cansign_;
}

int AForm::getGrade_canexec() const {
	return grade_canexec_;
}

void AForm::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= grade_cansign_) {
		is_signed_ = true;
	}
	else
		throw GradeTooLowException();
}

void AForm::executeForm(Bureaucrat const &executor) {
	if (this->is_signed_ == false)
		throw FormSignatureException();
	if (executor.getGrade() > this->grade_cansign_)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm &src) {
	out << "AForm name: " << src.getName() << " Is signed: " << src.get_is_signed_() << " Authorized signatures: " << src.getGrade_cansign() << " and above. Authorized execution grade: " << src.getGrade_canexec() << " and above." << std::endl;
	return out;
}