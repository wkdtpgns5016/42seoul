#include "PhoneBook.hpp"

int PhoneBook::get_index_empty_contact()
{
    int i = 0;

    while (i < 8) {
        if (this->contact[i].get_index() < 0)
            return (i);
        i++;
    }
    return (i);
}

void    PhoneBook::del_contacts() {
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;
    int i = 0;

    contact[i].init_contact();
    i++;
    while (i < 8) {
        first = this->contact[i].get_frist_name();
        last = this->contact[i].get_last_name();
        nick = this->contact[i].get_nickname();
        phone = this->contact[i].get_phone_number();
        secret = this->contact[i].get_darkest_secret();
        this->contact[i - 1].change_contact(i, first, last, nick, phone, secret);
        i++;
    }
    
}
int    PhoneBook::command_add(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    int index;
    
    index = get_index_empty_contact();
    if (index < 8)
        this->contact[index].change_contact(index + 1, first_name, last_name, nickname, phone_number, darkest_secret);
    else {
        del_contacts();
        this->contact[7].change_contact(8, first_name, last_name, nickname, phone_number, darkest_secret);
    }
    return 0;
}
int    PhoneBook::command_search()
{
    int index, flag;
    std::string str;

    index = 0;
    flag = 0;
    std::cout << std::endl;
    std::cout << "================Contact list================" << std::endl;
    std::cout << "     index|first_name| last_name| nick_name" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (this->contact[i].get_index() >= 0)
        {
            this->contact[i].print_contact_list();
            flag = 1;
        }
    }
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    if (!flag)
        std::cout << "Error: Contact does not exist\n";
    while (flag)
    {
        std::cout << "INDEX: ";
		std::getline(std::cin, str);
        if (std::cin.eof())
            return 1;
        if (!(str[0] > '0' && str[0] < '9') || str.length() != 1)
        {
            std::cout << "Error: Index is Out of range\n";
            continue ;
        }
        else
        {
            index = str[0] - '0';
            if (this->contact[index - 1].get_index() != index)
            {
                std::cout << "Error: Index is Out of range\n";
                continue ;
            }
            else
            {
                std::cout << std::endl;
                this->contact[index - 1].print_contact();
                std::cout << std::endl;
                break ;
            }
        }
    }
    return 0;
}
