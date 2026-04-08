#include "ClapTrap.hpp"

/*
*************** Constructors *************** 
*/

ClapTrap::ClapTrap() : name_("default") {

	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : name_(name) {

	std::cout << "ClapTrap parameterized constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : 
	name_(other.name_), 
	hitPoints_(other.hitPoints_), 
	energyPoints_(other.energyPoints_),
	attackDamage_(other.attackDamage_) {

	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {

	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	std::cout << "ClapTrap copy assignment operator called\n";

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor was called.\n";
}

/*
*************** Public Methods *************** 
*/

void ClapTrap::attack(const std::string &target) {

	if (hitPoints_ > 0 && energyPoints_ > 0) {	
		energyPoints_ -= 1;

		std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!\n";
	}
	else {
		std::cout << name_ << " does not have enough hit or energy points to perform an attack on target.\n";
	}

}

void ClapTrap::takeDamage(unsigned int amount) {

	hitPoints_ -= amount;

	std::cout << "ClapTrap " << name_ << " takes damage! " << amount << " energy points have been lost!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (hitPoints_ > 0 && energyPoints_ > 0) {

		energyPoints_ -= 1;
		hitPoints_ += amount;

		std::cout << "ClapTrap " << name_ << " was repaired and has gained energyPoints by " << amount << "!\n";
	}
	else {
		std::cout << name_ << " does not have enough hit or energy points to be repaired.\n";
	}
	
}