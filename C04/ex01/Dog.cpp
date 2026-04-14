#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
	std::cout << "Default constructor: Dog object was created." << std::endl;
}

Dog::Dog(const std::string &type) : Animal("Dog"), brain(new Brain()) {
	(void)type;
	
	std::cout << "Parameterized constructor: Dog object was created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*other.brain);

	std::cout << "Copy constructor: Dog object was created." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Copy assignment operator: Dog object was assigned." << std::endl;
	
	if (this != &other) {
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Destructor: Dog object was destroyed." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Woof Woof" << std::endl;
}

void Dog::setIdea(std::string idea, int index) {
	this->brain->setIdea(idea, index);
}

std::string Dog::getIdea(int index) const {
	return this->brain->getIdea(index);
}