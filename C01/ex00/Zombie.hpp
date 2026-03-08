#include <string>
#include <iostream>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

	private:
		std::string _name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void		announce(void);
		std::string get_name(void);
};

#endif
