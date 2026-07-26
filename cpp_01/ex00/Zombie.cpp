#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << msg << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "The zombie " << this->name;
    std::cout << " has been freed from the memory" << std::endl;
}
