#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template <typename T>

class Array {
  public:
    Array();
  
  private:
    T *arr_;
    std::size_t size;

};

#endif