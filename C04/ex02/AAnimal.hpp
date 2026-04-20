#ifndef AANIMAL_H
 # define AANIMAL_H

#include <string>

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif