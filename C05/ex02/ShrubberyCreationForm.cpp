#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target_(src.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
			AForm::operator=(src);
			target_ = src.target_;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute() const {

	std::string str1 = "    *    ";
	std::string str2 = "   ***   ";
	std::string str3 = "  *****  ";
	std::string str4 = "    |    ";
	std::string str5 = "    |    ";
				
	std::string outfile = target_ + "_shrubbery.txt";

	std::ofstream outputFile(outfile, std::ios::out);
	if (!outputFile.is_open()) {
		std::cerr << "Error creating output file" << std::endl;
		return;
	}

	outputFile << str1 << std::endl;
	outputFile << str2 << std::endl;
	outputFile << str3 << std::endl;
	outputFile << str4 << std::endl;
	outputFile << str5 << std::endl;

	outputFile.close();
	return;
}