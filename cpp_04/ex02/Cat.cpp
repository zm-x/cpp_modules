#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called\n";
    type = "Cat";
    brain = new Brain;
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called\n";
    brain = new Brain(*cat.brain);
}

Cat& Cat::operator=(const Cat &a)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &a)
    {
        Animal::operator=(a);
        delete brain;
        brain = new Brain(*a.brain);
    }
    return *this;
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
    std::cout << "Cat said meow meow nigga\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete brain;
}
