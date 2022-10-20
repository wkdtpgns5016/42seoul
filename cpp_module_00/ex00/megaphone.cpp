#include <iostream>

void    print_upper(char *str)
{
    std::string str1 = str;
    while (*str != 0)
    {
        std::cout << (char)toupper(*str);
        str++;
    }
}

int main(int ac, char **av) 
{
    int i = 1;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (i < ac)
        print_upper(av[i++]);
    std::cout << std::endl;
    return 0;
}