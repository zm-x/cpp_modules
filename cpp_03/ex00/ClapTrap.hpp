#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_points;
    public:
        ClapTrap();
        ClapTrap(std::string const &name);
        ClapTrap(ClapTrap const &claptrap);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &a);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif