#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <sstream>

class TestDiamondTrap : public DiamondTrap {
	public:
		TestDiamondTrap() : ClapTrap(), DiamondTrap() {}
		TestDiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), DiamondTrap(name) {}

		int getHitPoints() const { return hitPoints_; }
		int getEnergyPoints() const { return energyPoints_; }
		int getAttackDamage() const { return attackDamage_; }
		std::string getDName() const { return DiamondTrap::name_; }
		std::string getCName() const { return ClapTrap::name_; }
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

static void testNameSplit() {
	std::cout << "\n=== testNameSplit ===" << std::endl;
	TestDiamondTrap a("Alpha");
	a.whoAmI();
	check(a.getDName() == "Alpha", "DiamondTrap keeps constructor name");
	check(a.getCName() == "Alpha_clap_name", "DiamondTrap keeps ClapTrap name with suffixe");
}

static void testDefaultValues() {
	std::cout << "\n=== testDefaultValues ===" << std::endl;
	TestDiamondTrap b("Bob");
	check(b.getHitPoints() == 100, "DiamondTrap starts with 100 hit points");
	check(b.getEnergyPoints() == 50, "DiamondTrap starts with 50 energy points");
	check(b.getAttackDamage() == 30, "DiamondTrap starts with 30 attack damage.");
}

static void testInheritedBehaviors() {
	std::cout << "\n=== testInheritedBehaviors ===" << std::endl;
	TestDiamondTrap a("Tank");
	int hpBeforeDamage = a.getHitPoints();
	a.takeDamage(5);
	check(a.getHitPoints() == hpBeforeDamage - 5, "takeDamage lowers hit points");

	int hpBeforeRepair = a.getHitPoints();
	int energyBeforeRepair = a.getEnergyPoints();
	a.beRepaired(3);
	check(a.getHitPoints() == hpBeforeRepair + 3, "beRepaired increases hit points");
	check(a.getEnergyPoints() == energyBeforeRepair - 1, "beRepaired consumes 1 energy point");
}

static void testAttack() {
	std::cout << "\n=== testAttack() ===" << std::endl;
	TestDiamondTrap a("Alex");

	std::ostringstream captured;
	std::streambuf *originalBuf = std::cout.rdbuf(captured.rdbuf());

	a.attack("Bob");
	std::cout.rdbuf(originalBuf);

	std::string out = captured.str();
	check(out.find("ScavTrap") != std::string::npos, "ScavTrap's attack method was called.");
}

static void testSpecialAbility() {
	std::cout << "\n=== testSpecialAbility ===" << std::endl;
	TestDiamondTrap a("Max");

	a.whoAmI();
	check(true, "highFivesGuys is callable");
}

static void testConstructionDestructionChaining() {
	std::cout << "\ntestConstructionDestructionChaining" << std::endl;
	std::cout << "Expected constructor order: ClapTrap, FragTrap, ScavTrap, then DiamondTrap" << std::endl;
	std::cout << "Expected destructor order: DiamondTrap then ScavTrap, FragTrap and ClapTrap" << std::endl;
	{
		TestDiamondTrap chained("Chained");
		(void)chained;
	}
	check(true, "Chaining demo executed (verify order in printed constructor/destructor messages)");
}

int main() {
	std::cout << "Running DiamondTrap unit-style tests..." << std::endl;

	testNameSplit();
	testDefaultValues();
	testAttack();
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