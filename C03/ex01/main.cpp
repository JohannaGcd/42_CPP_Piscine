#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

class TestScavTrap : public ScavTrap {
public:
	TestScavTrap() : ScavTrap() {}
	TestScavTrap(const std::string &name) : ScavTrap(name) {}

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
	std::cout << "\n=== testDefaultValues ===" << std::endl;
	TestScavTrap a("Alpha");
	check(a.getName() == "Alpha", "ScavTrap keeps constructor name");
	check(a.getHitPoints() == 100, "ScavTrap starts with 100 hit points");
	check(a.getEnergyPoints() == 50, "ScavTrap starts with 50 energy points");
	check(a.getAttackDamage() == 20, "ScavTrap starts with 20 attack damage");
}

static void testAttackAndEnergyConsumption() {
	std::cout << "\n=== testAttackAndEnergyConsumption ===" << std::endl;
	TestScavTrap a ("Attacker");
	int beforeEnergy = a.getEnergyPoints();
	a.attack("target-1");
	check(a.getEnergyPoints() == beforeEnergy - 1, "ScavTrap attack consumes 1 energy point");
}

static void testInheritedBehaviors() {
	std::cout << "\n=== testInheritedBehaviors ===" << std::endl;
	TestScavTrap a("Tank");
	int hpBeforeDamage = a.getHitPoints();
	a.takeDamage(5);
	check(a.getHitPoints() == hpBeforeDamage - 5, "takeDamage lowers hit points");

	int hpBeforeRepair = a.getHitPoints();
	int energyBeforeRepair = a.getEnergyPoints();
	a.beRepaired(3);
	check(a.getHitPoints() == hpBeforeRepair + 3, "beRepaired increases hit points");
	check(a.getEnergyPoints() == energyBeforeRepair - 1, "beRepaired consumes 1 energy point");

	a.guardGate();
	check(true, "guardGate is callable");
}

static void testCopyConstructorAndAssignment() {
	std::cout << "\n=== testCopyConstructorAndAssignment ===" << std::endl;
	TestScavTrap original("Original");
	original.attack("dummy");
	original.takeDamage(10);

	TestScavTrap copied(original);
	check(copied.getName() == original.getName(), "Copy constructor copies name");
	check(copied.getHitPoints() == original.getHitPoints(), "Copy constructor copies hit points");
	check(copied.getEnergyPoints() == original.getEnergyPoints(), "Copy constructor copies energy points");
	check(copied.getAttackDamage() == original.getAttackDamage(), "Copy constructor copies attack damage");

	TestScavTrap assigned("Assigned");
	assigned = original;
	check(assigned.getName() == original.getName(), "Assignment copies name");
	check(assigned.getHitPoints() == original.getHitPoints(), "Assignment copies hit points");
	check(assigned.getEnergyPoints() == original.getEnergyPoints(), "Assignment copies energy points");
	check(assigned.getAttackDamage() == original.getAttackDamage(), "Assignment copies attack damage");
}

static void testConstructionDestructionChaining() {
	std::cout << "\n=== testConstructionDestructionChaining ===" << std::endl;
	std::cout << "Expected constructor order: ClapTrap then ScavTrap" << std::endl;
	std::cout << "Expected destructor order: ScavTrap then ClapTrap" << std::endl;
	{
		TestScavTrap chained("Chained");
		(void)chained;
	}
	check(true, "Chaining demo executed (verify order in printed constructor/destructor messages)");
}

int main() {
	std::cout << "Running ScavTrap unit-style tests..." << std::endl;

	testDefaultValues();
	testAttackAndEnergyConsumption();
	testInheritedBehaviors();
	testCopyConstructorAndAssignment();
	testConstructionDestructionChaining();

	std::cout << "\n=== Summary ===" << std::endl;
	std::cout << "Passed: " << g_passed << std::endl;
	std::cout << "Failed: " << g_failed << std::endl;

	if (g_failed != 0)
		return 1;
	return 0;
}