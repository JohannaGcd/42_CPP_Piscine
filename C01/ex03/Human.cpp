#include "Weapon.hpp"
#include "Human.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
	_name = name;
};

void HumanA::attack(void) {
	std::cout << _name << " attacks with their weapon " << _weapon.getType() << std::endl;
};

void HumanB::attack(void) {
	std::cout << _name << " attacks with their weapon " << weapon.getType() << std::endl;
};