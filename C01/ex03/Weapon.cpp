#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon(std::string type) {
	type = _type;
};

std::string Weapon::getType(void) {
	return _type;
};

void Weapon::setType(std::string type) {
	_type = type;
};