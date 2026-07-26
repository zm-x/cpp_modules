#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    Brain *brain;
    public:
        Dog();
        Dog(Dog const &dog);
        Dog& operator=(const Dog &a);
        void makeSound() const;
        std::string getType() const;
        ~Dog();
};

#endif
