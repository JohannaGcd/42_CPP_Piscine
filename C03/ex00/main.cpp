#include "ClapTrap.hpp"

int main(void) {
	
    /* Test 1: Basic Construction */
    ClapTrap ct1("Alice");
    // alice starts with 10 HP, 10 energy
    
    /* Test 2: Single Attack */
    ct1.attack("Bob");
    // energy should now be 9
    
    /* Test 3: Exhaust Energy */
    for (int i = 0; i < 10; i++) {
        ct1.attack("Bob");  // 10 more attacks
    }
    ct1.attack("Bob");  // 11th attack should fail
    
    /* Test 4: Repair */
    ct1.beRepaired(5);  // should fail (no energy)
    
    /* Test 5: Copy Constructor */
    ClapTrap ct2(ct1);
    // verify ct2 is independent of ct1
    
    return 0;
}