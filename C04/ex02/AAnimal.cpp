#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
	std::cout << "Default constructor: AAnimal object was created." << std::endl;
}
AAnimal::AAnimal(const std::string &type) : type(type) {
	std::cout << "Parameterized constructor: AAnimal object was created." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << "Copy constructor: AAnimal object was created." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "Copy assignment operator: AAnimal object was assigned." << std::endl;

	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "Destructor: AAnimal object was destroyed." << std::endl;
}

std::string AAnimal::getType(void) const {
	return type;
}