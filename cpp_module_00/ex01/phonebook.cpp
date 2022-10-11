#include "PhoneBook.hpp"

int PhoneBook::get_index_empty_contact()
{
    int i = 0;

    while (i < 8) {
        if (this->contact[i].get_index() < 0)
            return (i);
        i++;
    }
    return (-1);
}

void    PhoneBook::del_contacts() {
    int i = 0;

    contact[i].init_contact();
    i++;
    while (i < 8) {
        
    }
    
}
void    PhoneBook::command_add(std::string first_name, std::string last_name, std::string nickname)
{
    int index;
    
    index = get_index_empty_contact();
    if (index >= 0)
        this->contact[index].change_contact(index, first_name, last_name, nickname);
    else {

    }
}
void    PhoneBook::command_search()
{
    int i = 0;

    while (i < 8 && this->contact[i].get_index() > 0) {
        this->contact[i].print_contact();
        i++;
    }
}
void    PhoneBook::command_exit() { exit(0); }