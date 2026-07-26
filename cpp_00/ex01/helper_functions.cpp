#include "phonebook.hpp"

int	ft_atoi(std::string nptr)
{
	int	i;
	int	r;
	int	sign;

	i = 0;
	r = 0;
	sign = 1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + nptr[i] - '0';
        if (r * sign < INT_MIN || r > INT_MAX)
            return (-1);
		i++;
	}
	return (r * sign);
}

int count_spaces(std::string str, int start)
{
    int i;

    if (!start)
    {
        i = 0;
        while (str[i] && str[i] == ' ')
            i++;
        return (i);
    }
    else
    {
        i = str.length() - 1;
        while (i != -1 && str[i] == ' ')
            i--;
        return (str.length() - 1 - i);
    }
    return 0;
}

int full_digits(std::string phone_number)
{
    int i = 0;
    while (phone_number[i])
    {
        if (!std::isdigit(phone_number[i]))
            return 0;
        i++;
    }
    return 1;
}

void    long_string(std::string str, int pipe)
{
    std::cout << std::setw(9) << str.substr(0, 9) << '.';
    if (pipe)
        std::cout << '|';
}

void    short_string(std::string str, int pipe)
{
    std::cout << std::setw(10) << str;
    if (pipe)
        std::cout << '|';
}

void    more_or_less(std::string str, int pipe)
{
        if (str.length() > 10)
            long_string(str, pipe);
        else
            short_string(str, pipe);
}

std::string cut_spaces(std::string tmp)
{
    std::string new_tmp = tmp.substr(count_spaces(tmp, 0), tmp.length() - count_spaces(tmp, 1));
    return (new_tmp);
}

std::string get_input(std::string type, int *cntrl_d)
{
    int empty = 1;
    std::string tmp;
    while (empty)
    {
        std::cout << type;
        if(!std::getline(std::cin, tmp))
        {
            *cntrl_d = 1;
            break;
        }
        tmp = cut_spaces(tmp);
        if (!tmp[0])
            std::cerr << RED "invalid input!" RESET "\n";
        else
            empty = 0;
    }
    return tmp;
}

std::string check_number(int *cntrl_d, std::string message)
{
    std::string phone_number;
    int not_number = 1;
    while (not_number)
    {
        phone_number = get_input(message, cntrl_d);
        if (*cntrl_d)
            break;
        if (!full_digits(phone_number))
            std::cerr << RED "There is non int in the number!" RESET "\n";
        else
            not_number = 0;
    }
    return phone_number;
}
