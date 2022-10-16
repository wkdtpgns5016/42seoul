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
    int i = 0;

    contact[i].init_contact();
    i++;
    while (i < 8) {
        first = this->contact[i].get_frist_name();
        last = this->contact[i].get_last_name();
        nick = this->contact[i].get_nickname();
        this->contact[i - 1].change_contact(i, first, last, nick);
        i++;
    }
    
}
void    PhoneBook::command_add(std::string first_name, std::string last_name, std::string nickname)
{
    int index;
    
    index = get_index_empty_contact();
    if (index < 8)
        this->contact[index].change_contact(index, first_name, last_name, nickname);
    else {
        del_contacts();
        this->contact[7].change_contact(index, first_name, last_name, nickname);
    }
}
void    PhoneBook::command_search()
{
    for (int i = 0; i < 8; i++)
    {
        if (this->contact[i].get_index() >= 0)
            this->contact[i].print_contact();
    }
}
