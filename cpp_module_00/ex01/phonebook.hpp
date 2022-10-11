#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class Contact {
private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;

public:
    Contact()
    {
        set_index(-1);
        set_first_name("");
        set_last_name("");
        set_nickname("");
    }
    void    change_contact(int index, std::string first_name, std::string last_name, std::string nickname)
    {
        set_index(index);
        set_first_name(first_name);
        set_last_name(last_name);
        set_nickname(nickname);
    }

    int get_index() { return this->index; }
    std::string get_frist_name() { return this->first_name; }
    std::string get_last_name() { return this->last_name; }
    std::string get_nickname() { return this->nickname; }

    void    set_index(int index) { this->index = index; }
    void    set_first_name(std::string first_name) { this->first_name = first_name; }
    void    set_last_name(std::string last_name) { this->last_name = last_name; }
    void    set_nickname(std::string nickname) { this->nickname = nickname; }

    void    init_contact()
    {
        set_index(-1);
        set_first_name("");
        set_last_name("");
        set_nickname("");
    }
    void    print_contact()
    {
        int i = 0;
        const char *s;
        std::string str = get_index() + "|" + get_frist_name() + "|" + get_last_name() + "|" + get_nickname();

        if (str.length() > 10)
        {
            s = str.c_str();
            while (i < 9)
                std::cout << s[i++];
            std::cout << "." << std::endl;
        }
        else
            std::cout << str << std::endl;
    }
};

class PhoneBook {
private:
    Contact contact[8];

public:
    int get_index_empty_contact()
    {
        int i = 0;

        while (i < 8) {
            if (this->contact[i].get_index() < 0)
                return (i);
            i++;
        }
        return (-1);
    }

    void    del_contacts() {
        int i = 0;

        contact[i].init_contact();
        i++;
        while (i < 8) {
            
        }
        
    }
    void    command_add(int index, std::string first_name, std::string last_name, std::string nickname)
    {
        int index;
        
        index = get_index_empty_contact();
        if (index >= 0)
            this->contact[index].change_contact(index, first_name, last_name, nickname);
        else {

        }
    }
    void    command_search()
    {
        int i = 0;

        while (i < 8 && this->contact[i].get_index() > 0) {
            this->contact[i].print_contact();
            i++;
        }
    }
    void    command_exit() { exit(0); }
};

#endif