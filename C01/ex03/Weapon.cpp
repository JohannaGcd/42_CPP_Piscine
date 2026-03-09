#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon(std::string type) {
	type = _type;
};

std::string Weapon::getType(void) {
	return _type;
};

void Weapon::set_type(std::string type) {
	_type = type;
};