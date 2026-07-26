#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(Cat const &cat);
        Cat& operator=(const Cat &a);
        void makeSound() const;
        std::string getType() const;
        ~Cat();
};

#endif