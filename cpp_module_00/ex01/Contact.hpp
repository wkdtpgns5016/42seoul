#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;

public:
    Contact();
    void    change_contact(int index, std::string first_name, std::string last_name, std::string nickname);

    int get_index();
    std::string get_frist_name();
    std::string get_last_name();
    std::string get_nickname();

    void    set_index(int index);
    void    set_first_name(std::string first_name);
    void    set_last_name(std::string last_name);
    void    set_nickname(std::string nickname);

    void    init_contact();
    void    print_contact();
};

#endif