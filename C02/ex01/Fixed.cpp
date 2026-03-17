#include "Fixed.hpp"

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;

	fixedPoint = 0;
};

Fixed::Fixed (const Fixed& src) {

	std::cout << "Copy constructor called" << std::endl;

	fixedPoint = src.fixedPoint;
	//fractionalBits ?
};

Fixed& Fixed::operator= (const Fixed& src) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src) {
		this->fixedPoint = src.fixedPoint;
	}
	return *this;
};

Fixed::Fixed (const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = nbr << fractionalBits;
};

Fixed::Fixed(const float flt) {
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(flt * (1 << fractionalBits));
};

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits (void) const {

	std::cout << "getRawBits member function called" << std::endl;

	return fixedPoint;
};

void Fixed::setRawBits(int const raw) {

	fixedPoint = raw << fractionalBits;
};

float Fixed::toFloat(void) const {

	return fixedPoint / 256;
};

int		Fixed::toInt (void) const {

	return fixedPoint * 256;
};
