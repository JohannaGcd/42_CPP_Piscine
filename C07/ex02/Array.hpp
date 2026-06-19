#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <iostream>

template <typename T>

class Array {
 public:
  Array() : arr_(NULL), size_(0) {};
  Array(unsigned int n) : arr_(n ? new T[n]() : NULL), size_(n) {};
  Array(Array& other) : arr_(other.arr_), size_(other.size_) {};

  void print_arr(void) {
    for (int i = 0; i < static_cast<int>(size_); i++) {
      std::cout << arr_[i];
    }
    std::cout << std::endl;
  };

  void print_size(void) { std::cout << size_ << std::endl; };

  void populate_arr(T val) {
    for (int i = 0; i < static_cast<int>(size_); i++) {
      arr_[i] = val;
    }
  }

 private:
  T* arr_;
  std::size_t size_;
};

#endif