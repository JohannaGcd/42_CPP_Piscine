#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>


static void printHeader(const std::string &title) {
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main(void) {
    printHeader("Setup source with ice and cure");
    IMateriaSource* src = new MateriaSource();
    AMateria *baseIce = new Ice();
    AMateria *baseCure = new Cure();
    src->learnMateria(baseIce);
    src->learnMateria(baseCure);
    delete baseIce;
    delete baseCure;

    printHeader("Basic behavior from subject");
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);

    printHeader("Unknown materia type returns null");
    AMateria *unknown = src->createMateria("fire");
    if (unknown == nullptr)
        std::cout << "OK: createMateria(\"fire\") returned nullptr" << std::endl;
    else {
        std::cout << "KO: createMateria(\"fire\") should be nullptr" << std::endl;
        delete unknown;
    }

    printHeader("Inventory - invalid indexes");
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(-1, *bob);

    printHeader("Unequip removes slot from use");
    me->unequip(0);
    me->use(0, *bob);

    printHeader("Character copy constructor keeps independent materia");
    Character alice("alice");
    alice.equip(src->createMateria("ice"));
    Character aliceCopy(alice);
    alice.unequip(0);
    alice.use(0, *bob);
    aliceCopy.use(0, *bob);

    printHeader("Character assignment keeps independent materia");
    Character charlie("charlie");
    Character dave("dave");
    charlie.equip(src->createMateria("cure"));
    dave = charlie;
    charlie.unequip(0);
    charlie.use(0, *bob);
    dave.use(0, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}