#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("player1")
{
    std::cout << "ScavTrap: default constructor called\n";
    hit_points = 100;
    energy_points = 50;
    attack_points = 20;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    std::cout << "ScavTrap: parametre constructor called\n";
    hit_points = 100;
    energy_points = 50;
    attack_points = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap) : ClapTrap(scavtrap)
{
    std::cout << "ScavTrap: copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &a)
{
    if (this != &a)
        ClapTrap::operator=(a);
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!hit_points || !energy_points)
        std::cout << "ScavTrap: " << name << " cant attack\n";
    else
    {
        std::cout << "ScavTrap: " << name << " attacked " << target << " and damage him by " << attack_points << "\n";
        energy_points--;
    }
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called\n";
}
