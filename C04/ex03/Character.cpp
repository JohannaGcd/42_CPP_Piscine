#include "Character.hpp"
#include <string>

Character::Character(std::string name) : ICharacter(), _name(name) {
	initInventory(_inventory);
}

Character::Character(const Character &other) : ICharacter(), _name(other._name) {
	copyInventory(other._inventory, _inventory);
}

Character &Character::operator=(const Character &other) {}
Character::~Character() {}

std::string const &Character::getName() const {}
void Character::equip(AMateria *m) {}
void Character::unequip(int idx) {}
void Character::use(int idx, ICharacter &target) {}

static void initInventory(AMateria **_inventory) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

static void copyInventory(AMateria *const *src, AMateria **dst) {
	for (int i = 0; i < 4; i++) {
		if (dst[i])
			dst[i] = src[i]->clone();
		else
			dst[i] = nullptr;
	}
}