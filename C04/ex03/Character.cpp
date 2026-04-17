#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

static void initInventory(AMateria **_inventory) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

static void initFloor(AMateria **_floor) {
	for (int i = 0; i < 100; i++)
		_floor[i] = nullptr;
}

static void copyInventory(AMateria *const *src, AMateria **dst) {
	for (int i = 0; i < 4; i++) {
		if (src[i])
			dst[i] = src[i]->clone();
		else
			dst[i] = nullptr;
	}
}

static void cleanInventory(AMateria **_inventory) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character::Character(std::string name) : ICharacter(), _name(name) {
	initInventory(_inventory);
	initFloor(_floor);
}

Character::Character(const Character &other) : ICharacter(), _name(other._name) {
	copyInventory(other._inventory, _inventory);
	initFloor(_floor);
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		cleanInventory(_inventory);
		cleanFloor();
		copyInventory(other._inventory, _inventory);
		initFloor(_floor);
	}
	return (*this);
}

Character::~Character() {
	cleanInventory(_inventory);
	cleanFloor();
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) { 
	if (m == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m)
			return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == nullptr) {
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx] == nullptr)
		return;
	if (_inventory[idx]) {
		int j = 0;
		while (_floor[j])
			j++;
		_floor[j] = _inventory[idx];
		_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx] == nullptr)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}

void Character::cleanFloor(void) {
	for (int i = 0; i < 100; i++) {
		if (_floor[i]) {
			delete _floor[i];
			_floor[i] = nullptr;
		}
	}
}