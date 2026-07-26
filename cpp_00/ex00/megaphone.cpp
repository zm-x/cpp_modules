#include <iostream>
#include <cctype>

void    ft_toupper(char *str)
{
    for(int i = 0; str[i]; i++)
        std::cout << (char)toupper(str[i]);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for(int i = 1; av[i]; i++)
            ft_toupper(av[i]);
    }
    std::cout << '\n';
    return (0);
}