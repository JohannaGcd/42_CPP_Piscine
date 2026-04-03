#include "ClapTrap.hpp"
#include <sstream>

static int g_passed = 0;
static int g_failed = 0;

class TestClapTrap : public ClapTrap {
    public:
        TestClapTrap() : ClapTrap() {};
        TestClapTrap(const std::string &name) : ClapTrap(name) {};

        int getHitPoints() const { return hitPoints_; }
        int getEnergyPoints() const { return energyPoints_; }
        int getAttackDamage() const { return attackDamage_; }
        std::string getName() const { return name_; }
};

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

static void testBasicConstruction() {
    std::cout << "\n=== testBasicConstruction ===" << std::endl;
    TestClapTrap a("Alice");
    check(a.getName() == "Alice", "ClapTrap keeps constructor name");
    check(a.getHitPoints() == 10, "ClapTrap starts with 10 HP");
    check(a.getEnergyPoints() == 10, "ClapTrap starts with 10 EP");
}

static void testSingleAttack() {
    std::cout << "\n=== testBasicConstruction ===" << std::endl;
    TestClapTrap a("Alice");
    a.attack("Bob");
    check(a.getEnergyPoints() == 9, "After attacking, EP should be 9");
}

static void testExhaustEnergyAndRepair() {
    TestClapTrap a("Alice");
    for (int i = 0; i < 10; i++) {
        a.attack("Bob");
    }
    check(a.getEnergyPoints() == 0, "After 10 attacks, EP are down to 0");

    std::ostringstream captured;
    std::streambuf *originalBuf = std::cout.rdbuf(captured.rdbuf());

    a.attack("Bob");
    a.beRepaired(5);
    std::cout.rdbuf(originalBuf);

    std::string out = captured.str();
    check(
        out.find("does not have enough hit or energy points to perform an attack on target.") != std::string::npos,
        "11th attack prints expected failure message");
    check(
        out.find("does not have enough hit or energy points to be repaired.") != std::string::npos,
        "Repair with 0 energy prints expected failure message");
}

static void testCopyConstructor() {
    TestClapTrap a;
    TestClapTrap b(a);
    b.attack("test");
    check(a.getEnergyPoints() == 10, "a EP should be 10");
    check(b.getEnergyPoints() == 9, "b EP should be 9 after an attack, proving it is an independant object from a");
}

int main(void)
{

    std::cout << "Running ClapTrap unit-style tests..." << std::endl;

    testBasicConstruction();
    testSingleAttack();
    testExhaustEnergyAndRepair();
    testCopyConstructor();

    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "Passed: " << g_passed << std::endl;
    std::cout << "Failed: " << g_failed << std::endl;

    if (g_failed != 0)
        return 1;
    return 0;
}