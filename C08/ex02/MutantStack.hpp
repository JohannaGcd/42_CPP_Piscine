#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// A stack uses containers, only it hides certain features to allow
// LIFO operations only, for safety.
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    // stdlib container assignments are designed to handle self-assignment safely, + no extra members in MutantStack
    MutantStack& operator=(const MutantStack& other) { std::stack<T>::operator=(other); return *this; }
    ~MutantStack() {}

    // we create an alias for typename std::deque<T>::iterator 
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

    // c is the internal container object inside std::stack, defined in the <stack> library
    // ie. if my stack uses a deque underneath, c is that instance.
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif
