#include "DiamondTrap.hpp"

/*
*************** Constructors *************** 
*/

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name_("Default") {
	std::cout << "DiamondTrap default constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name_(name) {
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(), ScavTrap(), name_(other.name_) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;

	if (this != &other) {
		ClapTrap::operator=(other);
		name_ = other.name_;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/*
*************** Public Methods ***************
*/

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My names are: " << name_ << " and " << ClapTrap::name_ << std::endl;
}