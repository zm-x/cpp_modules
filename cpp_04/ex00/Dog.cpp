#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
}

Dog::Dog(Dog const &dog) : Animal(dog){}

Dog& Dog::operator=(const Dog &a)
{
    if (this != &a)
        Animal::operator=(a);
    return *this;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Dog said woof woof\n";
}

Dog::~Dog(){}