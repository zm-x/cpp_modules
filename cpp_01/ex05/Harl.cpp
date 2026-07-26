#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[DEBUG] I love having extra bacon for my burger!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    int not_found = 1;
    void (Harl::*functions[4])(void) = {
                &Harl::debug,
                &Harl::info,
                &Harl::warning,
                &Harl::error
    };

    std::string levels[4] = {"DEBUG", "DEBUG", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            not_found = 0;
            break;
        }
    }
    if (not_found)
        std::cerr << "Error: we cant find your command comment\n";
}