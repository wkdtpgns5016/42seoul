#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    std::string conversion_field(std::string field);

public:
    Contact();
    void    change_contact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);

    int get_index();
    std::string get_frist_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_number();
    std::string get_darkest_secret();

    void    set_index(int index);
    void    set_first_name(std::string first_name);
    void    set_last_name(std::string last_name);
    void    set_nickname(std::string nickname);
    void    set_phone_number(std::string phone_number);
    void    set_darkest_secret(std::string darkest_secret);
    void    init_contact();
    void    print_contact();
    void    print_contact_list();
};

#endif