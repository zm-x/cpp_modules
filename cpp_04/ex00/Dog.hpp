#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog const &dog);
        Dog& operator=(const Dog &a);
        void makeSound() const;
        std::string getType() const;
        ~Dog();
};

#endif
