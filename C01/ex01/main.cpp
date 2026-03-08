#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	
	Zombie *zombieHorde = new Zombie[N]();

	for (int i = 0; i < N; i++) {
		zombieHorde[i].set_name(name);
	}
	return zombieHorde;
}

int main(void) {

	int N = 10;
	Zombie *Horde = zombieHorde(N, "Edward");
	
	for (int i = 0; i < N; i++) {
		Horde[i].announce();
	}
	delete[] Horde;
}
