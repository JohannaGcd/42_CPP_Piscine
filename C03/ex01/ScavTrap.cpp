#include "ScavTrap.hpp"

/*
*************** Constructors *************** 
*/

ScavTrap::ScavTrap() : ClapTrap() {

	std::cout << "ScavTrap default constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	
	std::cout << "ScavTrap parameterized constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_= other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

/*
*************** Public Methods *************** 
*/

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
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode" << std::endl;
}