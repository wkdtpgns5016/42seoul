#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
private:
    Contact contact[8];

public:
    int get_index_empty_contact();
    void    del_contacts();
    int    command_add(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
    int    command_search();
};

#endif