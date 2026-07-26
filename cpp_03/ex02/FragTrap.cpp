#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("player1")
{
    std::cout << "FragTrap: default constructor called\n";
    hit_points = 100;
    energy_points = 100;
    attack_points = 30;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
    std::cout << "FragTrap: parametre constructor called\n";
    hit_points = 100;
    energy_points = 100;
    attack_points = 30;
}

FragTrap::FragTrap(FragTrap const &Fragtrap) : ClapTrap(Fragtrap)
{
    std::cout << "FragTrap: copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap &a)
{
    if (this != &a)
        ClapTrap::operator=(a);
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " is requesting a high five! ✋\n";
}

void FragTrap::attack(const std::string& target)
{
    if (!hit_points || !energy_points)
        std::cout << "FragTrap: " << name << " cant attack\n";
    else
    {
        std::cout << "FragTrap: " << name << " attacked " << target << " and damage him by " << attack_points << "\n";
        energy_points--;
    }
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called\n";
}
