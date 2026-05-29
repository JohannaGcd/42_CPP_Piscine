#ifndef BASE_HPP
#define BASE_HPP

class Base {
 public:
  virtual ~Base();
};

class A;
class B;
class C;

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif