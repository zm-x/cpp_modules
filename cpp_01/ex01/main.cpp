#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(5, "Brainy");
    delete[] zombie;
}