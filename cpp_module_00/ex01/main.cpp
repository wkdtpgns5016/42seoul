#include "PhoneBook.hpp"

std::string	*get_info(void)
{
	std::string str;
	std::string info[3];
	
	str = "";
	while (str.compare(""))
	{
		std::cout << "Frist name: ";
		std::cin >> str;
		info[0] = str;
	}
	str = "";
	while (str.compare(""))
	{
		std::cout << "Last name: ";
		std::cin >> str;
		info[1] = str;
	}
	str = "";
	while (str.compare(""))
	{
		std::cout << "Nickname: ";
		std::cin >> str;
		info[2] = str;
	}
	return (info);
}

void	process(PhoneBook phoneBook, std::string command)
{
	std::string *info;

	if (command.compare("ADD"))
	{
		info = get_info();
		phoneBook.command_add(info[0], info[1], info[2]);
	}
	else if (command.compare("SEARCH"))
	{
		phoneBook.command_search();
	}
	else if (command.compare("EXIT"))
	{
		phoneBook.command_exit();
	}
}

int main(int ac, char **av) 
{
    PhoneBook   phoneBooks;
    std::string command;
    int         exit_flag = 1;

    while (!exit_flag)
    {
        std::cin >> command;
		process(phoneBooks, command);
    }
    return 0;
}