#include "Zombie.hpp"

int main()
{
    Zombie* z = newZombie("Walker");
    z->announce();
    delete z;
    randomChump("Biter");
}
