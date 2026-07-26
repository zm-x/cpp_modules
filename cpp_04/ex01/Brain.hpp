#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        ~Brain();
        std::string &get_ideas(int index);
};

#endif