#ifndef DIAMONDTRAP_H
 # define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name_;


	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap &other);
		virtual ~DiamondTrap();

		void attack(const std::string &target) override;
		void whoAmI();
};

#endif