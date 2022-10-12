#include "Contact.hpp"

Contact::Contact()
{
    init_contact();
}

void    Contact::change_contact(int index, std::string first_name, std::string last_name, std::string nickname)
{
    set_index(index);
    set_first_name(first_name);
    set_last_name(last_name);
    set_nickname(nickname);
}

void    Contact::init_contact()
{
    set_index(-1);
    set_first_name("");
    set_last_name("");
    set_nickname("");
}

void    Contact::print_contact()
{
    int i = 0;
    const char *s;

    std::string str = get_frist_name() + "|" + get_last_name() + "|" + get_nickname();
    std::cout << get_index() << "|";
    if (str.length() > 8)
    {
        s = str.c_str();
        while (i < 7)
            std::cout << s[i++];
        std::cout << "." << std::endl;
    }
    else
    {
        std::cout << str << std::endl;
    }
}

int Contact::get_index() { return this->index; }
std::string Contact::get_frist_name() { return this->first_name; }
std::string Contact::get_last_name() { return this->last_name; }
std::string Contact::get_nickname() { return this->nickname; }

void    Contact::set_index(int index) { this->index = index; }
void    Contact::set_first_name(std::string first_name) { this->first_name = first_name; }
void    Contact::set_last_name(std::string last_name) { this->last_name = last_name; }
void    Contact::set_nickname(std::string nickname) { this->nickname = nickname; }