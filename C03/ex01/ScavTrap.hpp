#ifndef SCAVTRAP_H
 # define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		int hitPoints_ = 100;
		int energyPoints_ = 50;
		int attackDamage_ = 20;

	public:
		ScavTrap() : ;
		ScavTrap(const std::string &name) : ClapTrap(name) {};
		void guardGate();
		void attack(const std::string &target) override;
};

#endif