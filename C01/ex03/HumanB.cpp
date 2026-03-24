#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {};

void HumanB::attack(void) {
	if (_weapon)
		std::cout << _name << " attacks with their weapon " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon* weapon) {
	_weapon = weapon;
}