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
    void    command_add(std::string first_name, std::string last_name, std::string nickname);
    void    command_search();
};

#endif