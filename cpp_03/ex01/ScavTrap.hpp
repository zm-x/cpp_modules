#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &scavtrap);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &a);
        void attack(const std::string& target);
        void guardGate();
};

#endif