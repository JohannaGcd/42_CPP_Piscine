#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main() {
    MutantStack<int> mstack;

    // Demonstrates LIFO stack behavior
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    // Add more values
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Get iterators
    MutantStack<int>::iterator it = mstack.begin(); //
    MutantStack<int>::iterator ite = mstack.end();

    // Iterate over the stack, print each value
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Copy into a real stack
    std::stack<int> s(mstack);

    // compare with std::list, should show the same values
    // proving MutantStack iterator works 
    std::cout << "--- list check ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;

    return 0;
}
