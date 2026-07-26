#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
}

Cat::Cat(Cat const &cat) : Animal(cat){}

Cat& Cat::operator=(const Cat &a)
{
    if (this != &a)
        Animal::operator=(a);
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

Cat::~Cat(){}
