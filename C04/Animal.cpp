#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Default constructor: Animal object was created." << std::endl;
}
Animal::Animal(const std::string &type) : type(type) {
	std::cout << "Parameterized constructor: Animal object was created." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Copy constructor: Animal object was created." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Copy assignment operator: Animal object was assigned." << std::endl;

	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Destructor: Animal object was destroyed." << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Generic animal sound" << std::endl;
}