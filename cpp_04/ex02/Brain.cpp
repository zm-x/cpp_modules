#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain assignment operator called\n";
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

std::string &Brain::get_ideas(int index)
{
    return ideas[index];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}