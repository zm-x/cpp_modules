#include <iostream>

#define BLUE "\033[1;36m"
#define RESET "\033[0m\n"

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *brain_pointer = &brain;
    std::string &brain_reference = brain;
    std::cout << "memory address of variable is " << BLUE << &brain << RESET;
    std::cout << "memory address of pointer is " << BLUE << brain_pointer << RESET;
    std::cout << "memory address of reference is " << BLUE << &brain_reference << RESET;
    std::cout << "value of variable is " << BLUE << brain << RESET;
    std::cout << "value of pointer is " << BLUE << *brain_pointer << RESET;
    std::cout << "value of reference is " << BLUE << brain_reference << RESET;
}