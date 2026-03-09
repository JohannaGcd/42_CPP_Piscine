#include "Weapon.hpp"

int main() {
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club); // include name in constructor
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	return 0;
}