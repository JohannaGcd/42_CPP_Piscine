#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), brain(new Brain()) {
	std::cout << "Default constructor: Cat object was created." << std::endl;
}

Cat::Cat(const std::string &type) : AAnimal("Cat"), brain(new Brain()) {
	(void)type;

	std::cout << "Parameterized constructor: Cat object was created." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	this->brain = new Brain(*other.brain);

	std::cout << "Copy constructor: Cat object was created." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Copy assignment operator: Cat object was assigned." << std::endl;

	if (this != &other) {
		AAnimal::operator=(other);
		*this->brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Destructor: Cat object was destroyed." << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(std::string idea, int index) {
	this->brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const {
	return this->brain->getIdea(index);
}