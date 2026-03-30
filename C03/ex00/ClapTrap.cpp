#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target) {

	if (hitPoints_ > 0 && energyPoints_ > 0) {	
		energyPoints_ -= 1;

		std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
	}
	else {
		std::cout << name_ << "does not have enough hit or energy points to perform an attack on target." << std::endl;
	}

};

void ClapTrap::takeDamage(unsigned int amount) {
	energyPoints_ -= amount;
	std::cout << "ClapTrap " << name_ << " takes damage! " << amount << "energy points have been lost!" << std::endl;
	// if energypoints < 0, do we print a death message? call deconstructor?
};

void ClapTrap::beRepaired(unsigned int amount) {

	if (hitPoints_ > 0 && energyPoints_ > 0) {
		energyPoints_ -= 1;
		hitPoints_ += amount;

		std::cout << "ClapTrap " << name_ << " was repaired and has gained energyPoints by " << amount << "!" << std::endl;
	}
	else {
		std::cout << name_ << "does not have enough hit or energy points to be repaired." << std::endl;
	}
	
};