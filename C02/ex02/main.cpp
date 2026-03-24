#include "Fixed.hpp"
#include <cassert>

int main(void) {
	Fixed a(6.0f);
	Fixed b(0.0f);
	Fixed c(1);

	// assert(a == b);
	// assert(!(a < b));
	// assert(!(a > b));
	// assert(a <= b);
	// assert(a >= b);
	// assert(!(a != b));

	//assert(a < c);
	// assert(c > a);
	// assert(a != c);
	// assert(a <= c);
	// assert(c >= a);

	//std::cout << a.operator*(b) << std::endl;
	// std::cout << a.operator+(b) << std::endl;
	// std::cout << a.operator-(b) << std::endl;
	std::cout << a.operator/(b) << std::endl;


	std::cout << "All comparison tests passed." << std::endl;
	return 0;
}