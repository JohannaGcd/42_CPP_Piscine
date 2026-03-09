#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMAN_H
# define HUMAN_H

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
};

class HumanB {
	private:
		std::string _name;
		Weapon _weapon;

	public:
		HumanB(std::string name);

		void attack(void);
};

#endif