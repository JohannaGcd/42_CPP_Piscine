#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

// Function template, which takes a const reference to a container of type T,
// an int value to search for in the container, and returns a const iterator pointing
// to the found element, otherwise it throws an error.
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

#endif
