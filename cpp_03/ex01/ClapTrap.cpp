#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap: default constructor called\n";
    name = "ana";
    hit_points = 10;
    energy_points = 10;
    attack_points = 0;
}

ClapTrap::ClapTrap(std::string const &name)
{
    std::cout << "ClapTrap: parametre constructor called\n";
    this->name = name;
    hit_points = 10;
    energy_points = 10;
    attack_points = 0;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
    std::cout << "ClapTrap: copy constructor called\n";
    *this = claptrap;
}

void ClapTrap::attack(const std::string& target)
{
    if (!hit_points || !energy_points)
        std::cout << "ClapTrap: " << name << " cant attack\n";
    else
    {
        std::cout << "ClapTrap: " << name << " attacked " << target << " and damage him by " << attack_points << "\n";
        energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << name << " already dead tkays 3lih\n";
        return;
    }
    else if (amount > hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
    std::cout << name << " get attacked and lose " << amount << " hit_points\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!hit_points)
    {
        std::cout << name << " is dead and cannot be repaired!\n";
        return;
    }
    if (!energy_points)
    {
        std::cout << name << " failed to repair cuz he have no energy points left!\n";
        return;
    }
    energy_points--;
    std::cout << name << " repaired hit points from " << hit_points;
    hit_points += amount;
    std::cout << " to " << hit_points << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &a)
{
    if (this != &a)
    {
        this->name = a.name;
        this->hit_points = a.hit_points;
        this->energy_points = a.energy_points;
        this->attack_points = a.attack_points;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called\n";
}