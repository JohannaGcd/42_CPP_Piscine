#ifndef WHATEVER_H
#define WHATEVER_H

#include <cstddef>

template <typename F> void foo(F&& f) {

}

template <typename T, typename F> void iter(T *arr, const std::size_t n, F f) {

}

#endif