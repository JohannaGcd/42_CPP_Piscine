#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {
		std::cout << "Default constructor: WrongCat object was created." << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal("Cat") {
	(void)type;
	std::cout << "Parameterized constructor: WrongCat object was created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Copy constructor: WrongCat object was created." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "Copy assignment operator: WrongCat object was assigned." << std::endl;

	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Destructor: WrongCat object was destroyed." << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow Meow" << std::endl;
}