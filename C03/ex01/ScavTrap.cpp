#include "ScavTrap.hpp"




void ScavTrap::attack(const std::string &target) {

	if (hitPoints_ > 0 && energyPoints_ > 0) {	
		energyPoints_ -= 1;

		std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
	}
	else {
		std::cout << name_ << " does not have enough hit or energy points to perform an attack on target." << std::endl;
	}

}

void ScavTrap::guardGate () {
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode" << std::enld;
}