#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Default constructor: Dog object was created." << std::endl;
}

Dog::Dog(const std::string &type) : Animal("Dog") {
	(void)type;
	std::cout << "Parameterized constructor: Dog object was created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy constructor: Dog object was created." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Copy assignment operator: Dog object was assigned." << std::endl;
	
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor: Dog object was destroyed." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Woof Woof" << std::endl;
}