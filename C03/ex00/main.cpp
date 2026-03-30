#include "ClapTrap.hpp"

int main(void) {
	ClapTrap A;
	ClapTrap B(A);
	ClapTrap C;
	ClapTrap D("Bob");

	C = A;

	D.attack("test");
	D.takeDamage(2);
	D.beRepaired(2);
}