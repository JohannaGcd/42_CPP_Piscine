#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    // template implementations should live in .hp
    template <typename InputIt>
    void addNumber(InputIt first, InputIt last) {
        // difference_type is the type used for distances between iterators
        // iterator_trait gives the type of the iterator
        typename std::iterator_traits<InputIt>::difference_type dist = std::distance(first, last);
        if (dist < 0)
            throw std::runtime_error("Span: invalid range");
        // converts dist to an unsigned size type before comparing it with the container size
        if (_data.size() + static_cast<size_t>(dist) > _maxSize)
            throw std::runtime_error("Span: adding range exceeds capacity");
        for (; first != last; ++first) {
            // iterators are like pointers, so we need to dereference the value to add it
            _data.push_back(*first);
        }
    }

    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> _data;
    unsigned int _maxSize;
};

#endif
