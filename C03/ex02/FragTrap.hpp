#ifndef FRAGTRAP_H
 # define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		virtual ~FragTrap();

		void highFivesGuys(void);
};

#endif