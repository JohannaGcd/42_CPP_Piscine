#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    // example from subject
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // large test
    const unsigned int N = 10000;
    std::vector<int> big;
    big.reserve(N); // tells the vector to pre-allocate memory for N elements
    std::srand(static_cast<unsigned int>(std::time(NULL))); // produces different values each time, by anchoring the generation of random values with the launching time
    for (unsigned int i = 0; i < N; ++i)
        big.push_back(std::rand());

    Span sp2(N);
    sp2.addNumber(big.begin(), big.end());
    try {
        std::cout << "big shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "big longest: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
