#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
    init_contact();
}

void    Contact::change_contact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    set_index(index);
    set_first_name(first_name);
    set_last_name(last_name);
    set_nickname(nickname);
    set_phone_number(phone_number);
    set_darkest_secret(darkest_secret);
}

void    Contact::init_contact()
{
    set_index(-1);
    set_first_name("");
    set_last_name("");
    set_nickname("");
    set_phone_number("");
    set_darkest_secret("");
}

void    Contact::print_contact()
{
    std::cout << "==================Contact===================" << std::endl;
    std::cout << "index: " << this->get_index() << std::endl;
    std::cout << "first_name: " << this->get_frist_name() << std::endl;
    std::cout << "last_name: " << this->get_last_name() << std::endl;
    std::cout << "nickname: " << this->get_nickname() << std::endl;
    std::cout << "phone_number: " << this->get_phone_number() << std::endl;
    std::cout << "darkest_secret: " << this->get_darkest_secret() << std::endl;
    std::cout << "============================================" << std::endl;
}

std::string Contact::conversion_field(std::string field)
{
    std::string str;
    int         len;
    const char  *s;

    str = "";
    if (field.length() <= 10)
    {
        len = 10 - field.length();
        while (len-- > 0)
            str += " ";
        str += field;
    }
    else
    {
        len = 0;
        s = field.c_str();
        while (len < 9)
        {
            str += std::string(1, s[len++]);
        }
        str += ".";
    }
    return (str);
}

void    Contact::print_contact_list()
{
    std::string str;

    std::cout << std::setw(10) << this->get_index() << "|";
    str = "";
    str += conversion_field(this->get_frist_name()) + "|";
    str += conversion_field(this->get_last_name()) + "|";
    str += conversion_field(this->get_nickname());
    std::cout << str << std::endl;
}

int Contact::get_index() { return this->index; }
std::string Contact::get_frist_name() { return this->first_name; }
std::string Contact::get_last_name() { return this->last_name; }
std::string Contact::get_nickname() { return this->nickname; }
std::string Contact::get_phone_number() { return this->phone_number; }
std::string Contact::get_darkest_secret() { return this->darkest_secret; }

void    Contact::set_index(int index) { this->index = index; }
void    Contact::set_first_name(std::string first_name) { this->first_name = first_name; }
void    Contact::set_last_name(std::string last_name) { this->last_name = last_name; }
void    Contact::set_nickname(std::string nickname) { this->nickname = nickname; }
void    Contact::set_phone_number(std::string phone_number) { this->phone_number = phone_number; }
void    Contact::set_darkest_secret(std::string darkest_secret) { this->darkest_secret = darkest_secret; }