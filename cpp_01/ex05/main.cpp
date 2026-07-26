#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cerr << "Error: The program accept one paramet\n";
    else
    {
        Harl harl;
        harl.complain((std::string)av[1]);
    }
}
