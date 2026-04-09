#ifndef WRONG_CAT_H
 # define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();

		void makeSound(void) const;
};

#endif