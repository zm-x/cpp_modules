#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "=== Creating Array of Animals ===\n";

    const Animal* animals[4];
    
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    
    std::cout << "\n=== Testing Animals ===\n";

    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n=== Deleting Animals ===\n";

    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    std::cout << "\n=== Deep Copy Test for Dog ===\n";

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "tmp scope end\n";
    }
    
    std::cout << "\n=== Deep Copy Test for Cat ===\n";
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    
    std::cout << "\n=== End of Program ===\n";
    return 0;
}