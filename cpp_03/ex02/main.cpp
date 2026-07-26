#include "FragTrap.hpp"

int main()
{
	std::cout << "### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap clap("Clappy");
		FragTrap frag("Fraggy");

		std::cout << "\033[34mTesting ClapTrap\033[0m" << std::endl;
		clap.attack("target1");
		clap.takeDamage(5);
		clap.beRepaired(3);

		std::cout << "\033[34mTesting FragTrap\033[0m" << std::endl;
		frag.attack("enemy");
		frag.takeDamage(50);
		frag.beRepaired(20);
		frag.highFivesGuys();

		std::cout << "\033[34mTesting FragTrap energy depletion\033[0m" << std::endl;
		for (int i = 0; i < 100; i++)
			frag.attack("dummy");
		frag.beRepaired(10);

		std::cout << "\033[34mTesting FragTrap death\033[0m" << std::endl;
		frag.takeDamage(200);
		frag.attack("target");
		frag.beRepaired(50);

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}