#include <iostream>
#include <string>


#ifndef ZOMBI_H
# define ZOMBI_H

class Zombie {
	private:
		std::string _name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void		announce(void);
		std::string get_name(void);
		void		set_name(std::string);
};

#endif
