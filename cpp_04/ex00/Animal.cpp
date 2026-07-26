#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
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

Animal::~Animal(){}