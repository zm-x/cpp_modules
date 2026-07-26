#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string const &name);
        FragTrap(FragTrap const &fragtrap);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &a);
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif