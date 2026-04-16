#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const {
    return new Ice();
}