#include "ClapTrap.hpp"

/*
*************** Constructors *************** 
*/

ClapTrap::ClapTrap() : name_("default") {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_= other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap deconstructor called" << std::endl;
}

/*
*************** Public Methods *************** 
*/

void ClapTrap::attack(const std::string &target) {
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
	}
	else {
		std::cout << name_ << " does not have enough hit or energy points to perform an attack on target" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints_ -= amount;
	std::cout << "ClapTrap " << name_ << " takes damage! " << amount << " energy points have been lost!" << std::endl;
	// add guard for amount below 0 ?
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		energyPoints_ -= 1;
		hitPoints_ += amount;
		std::cout << "ClapTrap " << name_ << " was repaired and has gained energyPoints by " << amount << "!" << std::endl;
	}
	else {
		std::cout << name_ << " does not have enough hit or energy points to be repaired" << std::endl;
	}
}

