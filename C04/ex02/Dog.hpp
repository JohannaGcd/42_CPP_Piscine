#ifndef DOG_H
 # define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *brain;

	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void makeSound(void) const override;
		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;
};

#endif