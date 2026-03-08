#include "Zombie.hpp"

Zombie *newZombie(std::string name) {

	Zombie *newZombie = new Zombie(name);

	return newZombie;
};

void randomChump(std::string name) {

	Zombie randomChump(name);
	randomChump.announce();
};

int main(void) {

	Zombie *Edward = newZombie("Edward");
	(*Edward).announce();

	randomChump("Jacob");

	delete Edward;
	Edward = NULL;
}