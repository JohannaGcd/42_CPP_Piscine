#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {
	Animal *j = new Dog();
	Dog *doggo = new Dog();

	doggo->setIdea("Bone", 0);


	delete j;
	delete doggo;
}