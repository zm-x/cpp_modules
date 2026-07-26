#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#define msg ": BraiiiiiiinnnzzzZ..."

class Zombie{
    private:
        std::string name;
    public:
        void setname(std::string name) {this->name = name;}
        void announce(void);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif