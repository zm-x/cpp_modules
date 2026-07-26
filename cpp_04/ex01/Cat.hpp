#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    Brain *brain;
    public:
        Cat();
        Cat(Cat const &cat);
        Cat& operator=(const Cat &a);
        void makeSound() const;
        std::string getType() const;
        ~Cat();
};

#endif