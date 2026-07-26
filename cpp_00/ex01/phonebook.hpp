#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RED "\033[1;31m"
#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define DEEP_BLUE "\033[1;34m"
#define SKY_BLUE "\033[1;36m"

class Contact {
    private:
        int         cntrl_d;
        int         index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        void    add(int index);
        void    print_data(Contact data);
        void    show_all_contact();
        void    print_contact_data();
        int     get_flag(int cntrl_d);
        int     get_index(int index);
};

class PhoneBook {
    public:
        int     enter_commande();
        void    get_contacts(Contact contact, int index);
        void    get_input(std::string input);
        void    handle_commands();
        void    search(int number, int index);

    private:
        std::string input;
        Contact contact[8];
};

int	ft_atoi(std::string nptr);
int count_spaces(std::string str, int start);
int full_digits(std::string phone_number);
void    long_string(std::string str, int pipe);
void    short_string(std::string str, int pipe);
void    more_or_less(std::string str, int pipe);
std::string cut_spaces(std::string tmp);
std::string get_input(std::string type, int *cntrl_d);
std::string check_number(int *cntrl_d, std::string message);

#endif