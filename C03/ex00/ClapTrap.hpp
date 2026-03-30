#ifndef CLASSTRAP_H
 # define CLASSTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string name_;
		int			hitPoints_ = 10;
		int			energyPoints_ = 10;
		int			attackDamage_ = 0;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string &target); // this is a string but should be a claptrpa object?
		void takeDamage (unsigned int amount);
		void beRepaired (unsigned int amount);
};

#endif 