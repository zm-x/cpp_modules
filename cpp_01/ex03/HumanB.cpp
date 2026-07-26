#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->weapon = &Weapon;
}
