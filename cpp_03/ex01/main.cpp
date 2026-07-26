#include "ScavTrap.hpp"

int main()
{
    std::cout << "### TESTING SCAVTRAP ###\n" << std::endl;
    {
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");

        std::cout << "\033[34mTesting ClapTrap\033[0m" << std::endl;
        clap.attack("target1");
        clap.takeDamage(5);
        clap.beRepaired(3);

        std::cout << "\033[34mTesting ScavTrap\033[0m" << std::endl;
        scav.attack("target2");
        scav.takeDamage(30);
        scav.beRepaired(20);
        scav.guardGate();

        std::cout << "\033[34mTesting ScavTrap with high damage\033[0m" << std::endl;
        scav.takeDamage(90);
        scav.attack("target3");

        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    return (0);
}