#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "Default constructor: Animal object was created." << std::endl;
}
WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
	std::cout << "Parameterized constructor: Animal object was created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "Copy constructor: Animal object was created." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "Copy assignment operator: Animal object was assigned." << std::endl;

	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor: Animal object was destroyed." << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Generic animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return type;
}