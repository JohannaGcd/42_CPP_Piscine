#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain: default constructor" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain: copy constructor" << std::endl;

	for (int i = 0; i < IDEAS_MAX; i++)
			this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain: copy assignment operator" << std::endl;

	if (this != &other) {
		for (int i = 0; i < IDEAS_MAX; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain: destructor" << std::endl;
}

void Brain::setIdea(std::string idea, int index) {
	if (index >= 0 && index < IDEAS_MAX)
		ideas[index] = idea;
	else
		std::cout << "Invalid index" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < IDEAS_MAX)
		return ideas[index];
	else
		return "Invalid index";
}