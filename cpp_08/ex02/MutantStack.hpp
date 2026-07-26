#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef std::stack<T> _stack;
    typedef typename _stack::container_type container_type;
    typedef typename container_type::iterator iterator;

    MutantStack() : _stack() {}
    MutantStack(const MutantStack &other) : _stack(other) {}
    MutantStack &operator=(const MutantStack &other) { _stack::operator=(other); return *this; }
    ~MutantStack() {}

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif