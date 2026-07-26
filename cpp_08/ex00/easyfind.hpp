#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class DidntFindIt : public std::exception
{
    virtual const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end())
        throw DidntFindIt();
    return it;
}

#endif