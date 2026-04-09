#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {
		std::cout << "Default constructor: Cat object was created." << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal("Cat") {
	(void)type;
	std::cout << "Parameterized constructor: Cat object was created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Copy constructor: Cat object was created." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "Copy assignment operator: Cat object was assigned." << std::endl;

	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Destructor: Cat object was destroyed." << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow Meow" << std::endl;
}