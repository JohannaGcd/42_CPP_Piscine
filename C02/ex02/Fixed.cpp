#include "Fixed.hpp"

/*
* *************** Constructors *************** 
*/

Fixed::Fixed () {
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
};

Fixed::Fixed (const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	operator=(src);
};

Fixed& Fixed::operator= (const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->fixedPoint = src.fixedPoint;
	return *this;
};

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = nbr << fractionalBits;
};

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(nbr * (1 << fractionalBits));
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

/*
* *************** Public Methods *************** 
*/

int Fixed::getRawBits (void) const {
	return fixedPoint;
};

void Fixed::setRawBits (int const raw) {
	fixedPoint = raw;
};

float Fixed::toFloat (void) const {
	return ((float)fixedPoint) / (1 << fractionalBits);
};

int Fixed::toInt (void) const {
	return fixedPoint >> fractionalBits;
};

/*
* *************** Print Operator *************** 
*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
};

/*
* *************** Comparison Operators *************** 
*/

bool Fixed::operator==(const Fixed &b) const {
	return fixedPoint == b.fixedPoint;
};

bool Fixed::operator<(const Fixed &b) const {
	return fixedPoint < b.fixedPoint;
};

bool Fixed::operator>(const Fixed &b) const {
	return fixedPoint > b.fixedPoint;
};

bool Fixed::operator<=(const Fixed &b) const {
	return fixedPoint <= b.fixedPoint;
};

bool Fixed::operator>=(const Fixed &b) const {
	return fixedPoint >= b.fixedPoint;
};

bool Fixed::operator!=(const Fixed &b) const {
	return fixedPoint != b.fixedPoint;
};

/*
* *************** Arithmetic Operator *************** 
*/

Fixed Fixed::operator+(const Fixed &b) const {
	Fixed res;
	res.setRawBits(fixedPoint + b.fixedPoint);
	return res;
};

Fixed Fixed::operator-(const Fixed &b) const {
	Fixed res;
	res.setRawBits(fixedPoint - b.fixedPoint);
	return res;
};

Fixed Fixed::operator*(const Fixed &b) const {
	Fixed res;
	long long temp = (long long)fixedPoint * (long long)b.fixedPoint;
	temp = temp / (1 << fractionalBits);
	res.setRawBits(temp);
	return res;
};

Fixed Fixed::operator/(const Fixed &b) const {
	Fixed res;
	
	if (b.fixedPoint == 0)
	{
		std::cout << "Unable to divide by 0" << std::endl;
		return res;
	}
	long long temp = ((long long)fixedPoint * (1 << fractionalBits)) / (long long)b.fixedPoint;
	res.setRawBits(temp);
	return res;
};

/*
* *************** Pre/Post Increment Operators *************** 
*/

Fixed& Fixed::operator++ (void) {
	fixedPoint = fixedPoint + 1;
	return *this;
};

Fixed& Fixed::operator-- (void) {
	fixedPoint = fixedPoint - 1;
	return *this;
};

Fixed Fixed::operator++ (int) {
	Fixed original = *this;
	fixedPoint = fixedPoint + 1;
	return original;
};

Fixed Fixed::operator-- (int) {
	Fixed original = *this;
	fixedPoint = fixedPoint - 1;
	return original;
};

/*
* *************** Pre/Post Increment Operators *************** 
*/

Fixed& Fixed::min (Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
};

const Fixed& Fixed::min (const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
};

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
};

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	return (a > b) ? a : b;
};
