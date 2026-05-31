#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
  std::srand(std::time({}));
  int random = std::rand() % 3;
  if (random == 0) {
    std::cout << "Created: A" << std::endl;
    return (new A);
  } else if (random == 1) {
    std::cout << "Created: B" << std::endl;
    return (new B);
  } else {
    std::cout << "Created: C" << std::endl;
    return (new C);
  }
}

void identify(Base* p) {

  A* a;
  B* b;
  C* c;

  a = dynamic_cast<A*>(p);
  if (a != nullptr)
    std::cout << "Object type: A" << std::endl;

  b = dynamic_cast<B*>(p);
  if (b != nullptr)
    std::cout << "Object type: B" << std::endl;

  c = dynamic_cast<C*>(p);
  if (c != nullptr)
    std::cout << "Object type: C" << std::endl;
}

void identify(Base& p) {

  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "Object type: A" << std::endl;
  } catch (std::bad_cast&) {
    try {
      B& b = dynamic_cast<B&>(p);
      (void)b;
      std::cout << "Object type: B" << std::endl;
    } catch (std::bad_cast&) {
      try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Object type: C" << std::endl;
      } catch (std::bad_cast&) {}
    }
  };
}

int main(void) {
  Base* p;
  p = generate();
  identify(p);
  identify(*p);

  delete p;

  return (0);
}
