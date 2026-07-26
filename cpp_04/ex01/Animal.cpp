#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called\n";
    type = "Animal";
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal copy constructor called\n";
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Animal assignment operator called\n";
    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal make sound\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}