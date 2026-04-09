#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal("Cat") {
		std::cout << "Default constructor: Cat object was created." << std::endl;
}

Cat::Cat(const std::string &type) : Animal("Cat") {
	(void)type;
	std::cout << "Parameterized constructor: Cat object was created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Copy constructor: Cat object was created." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Copy assignment operator: Cat object was assigned." << std::endl;

	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Destructor: Cat object was destroyed." << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Meow Meow" << std::endl;
}