#include <iostream>
#include <string>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

	private:
		std::string _type;

	public:
		Weapon::Weapon();
		Weapon::Weapon(std::string type);

		std::string getType(void);
		void set_type(std::string type);
};

#endif