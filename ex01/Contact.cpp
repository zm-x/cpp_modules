#include "phonebook.hpp"

int   Contact::get_flag(int cntrl_d)
{
    if (cntrl_d > -1)
        this->cntrl_d = cntrl_d;
    return (this->cntrl_d);
}   

int   Contact::get_index(int index)
{
    if (index > -1)
        this->index = index;
    return (this->index);
}

void    Contact::add(int index)
{
    int cntrl_d = 0;
    this->first_name = get_input(SKY_BLUE "First Name" RESET ": ", &cntrl_d);
    if (!cntrl_d)
        this->last_name = get_input(SKY_BLUE "Last Name" RESET ": ", &cntrl_d);
    if (!cntrl_d)
        this->nickname = get_input(SKY_BLUE "Nickname" RESET ": ", &cntrl_d);
    if (!cntrl_d)
        this->phone_number = check_number(&cntrl_d, SKY_BLUE "Phone Number" RESET ": ");
    if (!cntrl_d)
        this->darkest_secret = get_input(SKY_BLUE "Darkest Secret" RESET ": ", &cntrl_d);
    this->get_index(index);
    this->get_flag(cntrl_d);
}

void    Contact::show_all_contact()
{
    std::cout << "|-------------------------------------------|\n";
    std::cout << "|   " SKY_BLUE "index" RESET "  |" SKY_BLUE "first name" RESET;
    std::cout << "|" SKY_BLUE "last  name" RESET "| " SKY_BLUE "nickname" RESET " |\n";
    std::cout << "|-------------------------------------------|\n";
    std::cout << "|";
    std::cout << "         " << this->get_index(-1) + 1 << "|";
    more_or_less(this->first_name, 1);
    more_or_less(this->last_name, 1);
    more_or_less(this->nickname, 0);
    std::cout << "|\n";
    std::cout << "|-------------------------------------------|\n" << std::endl;
}

