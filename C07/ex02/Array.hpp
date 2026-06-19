#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <iostream>

template <typename T>

class Array 
{
  public:
    Array() : arr_(NULL), size_(0) {};
    ~Array() { delete[] arr_; }
    Array(unsigned int n) : arr_(n ? new T[n]() : NULL), size_(n) {};
    Array(const Array& other)
        : arr_(other.size_ ? new T[other.size_]() : NULL), size_(other.size_) 
    {
      for (std::size_t i = 0; i < size_; i++) 
      {
        arr_[i] = other.arr_[i];
      }
    }
    Array& operator=(const Array& other) 
    {
      if (this != &other)
      {
        T* temp = other.size_ ? new T[other.size_] : NULL;
        {
          for (std::size_t i = 0; i < other.size_; i++)
          {
            temp[i] = other.arr_[i];
          }
        }
        delete[] arr_;
        arr_ = temp;
        size_ = other.size_;
      }      
      return *this;
    }

    void print_arr(void) 
    {
      if (arr_ != NULL) 
      {
        for (int i = 0; i < static_cast<int>(size_); i++) 
            {
              std::cout << arr_[i];
            }
            std::cout << std::endl;
      }
      
    }

    std::size_t size(void) const
    { 
      return size_; 
    }

    void populate_arr(T val) 
    {
      if (arr_ != NULL && size_ > 0) 
      {
        for (int i = 0; i < static_cast<int>(size_); i++) 
            {
              arr_[i] = val;
            }
      }
    }

    T& operator[](std::size_t index) const 
    {
      if (index >= size_)
      {
        throw std::out_of_range("Array index out of bounds.");
      }
      return arr_[index];
    }


  private:
    T* arr_;
    std::size_t size_;
};

#endif