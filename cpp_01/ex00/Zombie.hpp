#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define msg ": BraiiiiiiinnnzzzZ..."
#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        void announce(void);
        Zombie(std::string name) : name(name){};
        ~Zombie();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif