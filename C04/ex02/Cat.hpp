#ifndef CAT_H
 # define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void makeSound(void) const override;
		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;
};

#endif