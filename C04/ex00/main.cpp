#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  const WrongAnimal *beta = new WrongAnimal();
  const WrongAnimal *k = new WrongCat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  std::cout << std::endl;

  std::cout << k->getType() << " " << std::endl;
  k->makeSound();

  delete meta;
  delete j;
  delete i;

  delete beta;
  delete k;

  return 0;
}