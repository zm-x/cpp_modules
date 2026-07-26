#include "easyfind.hpp"

const char *DidntFindIt::what() const throw()
{
    return "Value not found in container";
}
