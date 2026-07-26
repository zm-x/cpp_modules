#include "phonebook.hpp"

int    PhoneBook::enter_commande()
{
    std::cout << SKY_BLUE "enter one parameter " RESET ": ";
    if (!std::getline(std::cin, this->input))
    {
        std::cout << "\n" RED "program terminated!" RESET "\n";
        return 0;
    }
    return 1;
}

void    Contact::print_contact_data()
{
    std::cout << SKY_BLUE "first name: " RESET << this->first_name << '\n';
    std::cout << SKY_BLUE "last name: " RESET << this->last_name << '\n';
    std::cout << SKY_BLUE "nickname: " RESET << this->nickname << '\n';
    std::cout << SKY_BLUE "phone_number: " RESET << this->phone_number << '\n';
    std::cout << SKY_BLUE "darkest secret: " RESET << this->darkest_secret << '\n';
}

void    PhoneBook::search(int number, int index)
{
    int cntrl_d = 0;
    int error = 0;
    int input = 0;
    for (int i = 0; i <= number; i++)
    {
        this->contact[i].show_all_contact();
    }
    char c = '0' + (number + 1);
    std::cout << DEEP_BLUE "number of saved contacts is " RESET << GREEN << c << '\n' << RESET;
    input = ft_atoi(check_number(&cntrl_d, GREEN "enter index of the contact" RESET ": "));
    if (input < 1)
    {
        if (!cntrl_d)
            std::cout << RED "pick from 1 to 8 only\n" RESET;
        error = 1;
    }
    else if (input > number + 1)
    {
        if (!cntrl_d)
            std::cout << RED "there is no contact saved with that index\n" RESET;
        error = 1;
    }
    if (!error)
        this->contact[input - 1].print_contact_data();
    this->contact[index].get_flag(cntrl_d);
}

void    PhoneBook::handle_commands()
{
    int index = 0;
    int number = -1;
    while (true)
    {
        if (!this->enter_commande())
            break;
        if (this->input == "ADD")
        {
            this->contact[index].add(index);
            if (this->contact[index].get_flag(-1))
            {
                std::cout << "\n" RED "program terminated!" RESET "\n";
                break;
            }
            if (number < 7)
                number++;
            index = (index + 1) % 8;
            std::cout << GREEN "Information stored successfully!" RESET "\n";
        }
        else if (this->input == "SEARCH")
        {
            this->search(number, index);
            if (this->contact[index].get_flag(-1))
            {
                std::cout << "\n" RED "program terminated!" RESET "\n";
                break;
            }
        }
        else if (this->input == "EXIT")
        {
            std::cout << RED "program terminated!" RESET "\n";
            break;
        }
        else
            std::cout << "ayeh ayeh fhmtk\n";
    }
}


