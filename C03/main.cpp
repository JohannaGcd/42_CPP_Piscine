#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class TestFragTrap : public FragTrap {
	public:
		TestFragTrap() : FragTrap() {}
		TestFragTrap(const std::string &name) : FragTrap(name) {}

		int getHitPoints() const { return hitPoints_; }
		int getEnergyPoints() const { return energyPoints_; }
		int getAttackDamage() const { return attackDamage_; }
		std::string getName() const { return name_; }
};

static int g_passed = 0;
static int g_failed = 0;

static void check(bool condition, const std::string &label) {
	if (condition) {
		std::cout << "[PASS] " << label << std::endl;
		++g_passed;
	}
	else {
		std::cout << "[FAIL] " << label << std::endl;
		++g_failed;
	}
}

static void testDefaultValues() {
	std::cout << "\n=== testConstructors ===" << std::endl;
	TestFragTrap a("Alpha");
	check(a.getName() == "Alpha", "FragTrap keeps constructor name");
	check(a.getHitPoints() == 100, "FragTrap starts with 100 hit points");
	check(a.getEnergyPoints() == 100, "FragTrap starts with 100 energy points");
	check(a.getAttackDamage() == 30, "FragTrap starts with 30 attack damage.");
}

static void testInheritedBehaviors() {
	std::cout << "\n=== testInheritedBehaviors ===" << std::endl;
	TestFragTrap a("Tank");
	int hpBeforeDamage = a.getHitPoints();
	a.takeDamage(5);
	check(a.getHitPoints() == hpBeforeDamage - 5, "takeDamage lowers hit points");

	int hpBeforeRepair = a.getHitPoints();
	int energyBeforeRepair = a.getEnergyPoints();
	a.beRepaired(3);
	check(a.getHitPoints() == hpBeforeRepair + 3, "beRepaired increases hit points");
	check(a.getEnergyPoints() == energyBeforeRepair - 1, "beRepaired consumes 1 energy point");
}

static void testSpecialAbility() {
	std::cout << "\n=== testSpecialAbility ===" << std::endl;
	TestFragTrap a("Max");

	a.highFivesGuys();
	check(true, "highFivesGuys is callable");
}

static void testConstructionDestructionChaining() {
	std::cout << "\ntestConstructionDestructionChaining" << std::endl;
	std::cout << "Expected constructor order: ClapTrap, then FragTrap" << std::endl;
	std::cout << "Expected destructor order: FragTrap then ClapTrap" << std::endl;
	{
		TestFragTrap chained("Chained");
		(void)chained;
	}
	check(true, "Chaining demo executed (verify order in printed constructor/destructor messages)");
}

int main() {
	std::cout << "Running FragTrap unit-style tests..." << std::endl;

	testDefaultValues();
	testInheritedBehaviors();
	testSpecialAbility();
	testConstructionDestructionChaining();

	std::cout << "\n=== Summary ===" << std::endl;
	std::cout << "Passed: " << g_passed << std::endl;
	std::cout << "Failed: " << g_failed << std::endl;

	if (g_failed != 0)
		return 1;
	return 0;
}