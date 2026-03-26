#include "Fixed.hpp"

Fixed::Fixed () {
    std::cout << "Default constructor called" << std::endl;

    fixedPoint = 0;
};

Fixed::Fixed (const Fixed &oldFixed) {
    fixedPoint = oldFixed.fixedPoint;

    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator= (const Fixed& other) {
    
    if (this != &other) {

        this->fixedPoint = other.fixedPoint;
    }

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
};

Fixed::~Fixed () {
    std::cout << "Destructor called" << std::endl;
};

int     Fixed::getRawBits (void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;
};

void Fixed::setRawBits(int const raw) {
    fixedPoint = raw;
};