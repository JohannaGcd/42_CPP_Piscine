#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {
	std::cout << "[1] Polymorphism through Animal*" << std::endl;
	Animal *zoo[2];
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[0]->makeSound();
	zoo[1]->makeSound();

	std::cout << "\n[2] Deep copy check (Dog)" << std::endl;
	Dog original;
	original.setIdea("Bone", 0);
	Dog copy = original;
	original.setIdea("Ball", 0);
	std::cout << "original idea: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea: " << copy.getIdea(0) << std::endl;

	std::cout << "\n[3] Cleanup through base pointers" << std::endl;
	delete zoo[0];
	delete zoo[1];

	return 0;
}