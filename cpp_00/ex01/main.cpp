#include "phonebook.hpp"

int main()
{
    std::cout << GREEN "ADD" RESET ": save a new contact\n";
    std::cout << DEEP_BLUE "SEARCH" RESET ": display a specific contact\n";
    std::cout << RED "EXIT" RESET ": exit from the program\n";
    PhoneBook book_data;
    book_data.handle_commands();
}