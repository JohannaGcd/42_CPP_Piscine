#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string name) {
	_name = name;
};

Zombie::~Zombie() {
	std::cout << get_name() << "  was destroyed." << std::endl;
};

std::string Zombie::get_name(void) {
	return _name;
};

void Zombie::set_name(std::string str) {
	_name = str;
};

void Zombie::announce(void) {
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};



