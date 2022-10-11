#include "phonebook.hpp"

void    print_phone_book(PhoneBook phoneBook)
{
    int i = 0;
    const char *s;
    std::string str = phoneBook.first_name + "|" + phoneBook.name + "|" + phoneBook.nickname + "|" + phoneBook.phone_number + "|" + phoneBook.secret;

    if (str.length() > 10)
    {
        s = str.c_str();
        while (i < 9)
            std::cout << s[i++];
        std::cout << "." << std::endl;
    }
}

int    process_command(PhoneBook *phoneBooks, std::string str, int *exit_code)
{
    if (str.compare("ADD") == 0)
    {

    }
    else if (str.compare("SEARCH") == 0)
    {

    }
    else if (str.compare("EXIT") == 0)
        *exit_code = 0;
}

int main(int ac, char **av) 
{
    PhoneBook   phoneBooks[8];
    std::string command;
    int         exit_flag = 1;

    while (!exit_flag)
    {
        std::cin >> command;
        exit_flag = process_command(phoneBooks, command, &exit_flag);
    }
    return 0;
}