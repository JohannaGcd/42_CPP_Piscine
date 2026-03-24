#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMAN_H_B
# define HUMAN_H_B

class HumanB {

	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(std::string name);

		void setWeapon(Weapon* weapon);
		void attack(void);
};

#endif