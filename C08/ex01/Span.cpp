#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _data(), _maxSize(N) {}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _data = other._data;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span: full");
    _data.push_back(n);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    int mn = *std::min_element(_data.begin(), _data.end());
    int mx = *std::max_element(_data.begin(), _data.end());
    return mx - mn;
}
