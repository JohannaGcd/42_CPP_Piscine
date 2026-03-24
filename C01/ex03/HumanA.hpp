#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMAN_H_A
# define HUMAN_H_A

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
};

#endif