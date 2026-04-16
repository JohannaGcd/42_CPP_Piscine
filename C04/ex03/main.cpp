#include "AMateria.hpp"
#include "Ice.hpp"

int main(void) {

    Ice Test;
    Ice *Test2;
    Test2 = Test.clone();
    delete Test2;

}