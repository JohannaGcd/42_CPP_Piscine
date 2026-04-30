#include "Form.hpp"

Form::Form(const std::string name, const int grade_cansign, const int grade_canexec) : name_(name), grade_cansign_(grade_cansign), grade_canexec_(grade_canexec) : name_(name) {
	if (grade_cansign < 1 || grade_canexec
	
	// TODO include exceptions here
	, const int grade_canexec) : name_(name), grade_cansign_(grade_cansign);
	
	grade_canexec_(grade_canexec)
}


Form::Form(const Form &src) : name_(src.name_), is_signed_(src.is_signed_), grade_cansign_(src.grade_cansign_), grade_canexec_(src.grade_canexec_) {}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		is_signed_ = src.is_signed_;
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const {
	return name_;
}

bool Form::get_is_signed_() const {
	return is_signed_;
}

int Form::getGrade_cansign() const {
	return grade_cansign_;
}

int Form::getGrade_canexec() const {
	return grade_canexec_;
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= grade_cansign_) {
		is_signed_ = true;
	}
	else
		throw GradeTooLowException();
}



std::ostream &operator<<(std::ostream &out, Form &src) {
	out << "Form name: " << src.getName() << " Is signed: " << src.get_is_signed_() << " Authorized signatures: " << src.getGrade_cansign() << " and above. Authorized execution grade: " << src.getGrade_canexec() << " and above." << std::endl;
	return out;
}