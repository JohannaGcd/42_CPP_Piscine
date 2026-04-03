#include "FragTrap.hpp"

/*
*************** Constructors *************** 
*/

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;

	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
};

FragTrap::~FragTrap() {
	std::cout << "FragTrap deconstructor called" << std::endl;
};

/*
*************** Public Methods ***************
*/

void highFivesGuys(void) {
	std::cout << "Let's high five!" << std::endl;
}