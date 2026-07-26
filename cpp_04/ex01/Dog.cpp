#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called\n";
    type = "Dog";
    brain = new Brain;
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called\n";
    brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(const Dog &a)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &a)
    {
        Animal::operator=(a);
        delete brain;
        brain = new Brain(*a.brain);
    }
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

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}