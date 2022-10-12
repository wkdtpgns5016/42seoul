#include "PhoneBook.hpp"

std::string get_info(std::string info)
{
	std::string str;
	
	str = "";
	while (str.compare("") == 0)
	{
		std::cout << info;
		std::cin >> str;
	}
	return (str);
}

void	process(PhoneBook *phoneBook, std::string command, int *exit)
{
	std::string first;
	std::string last;
	std::string nick;

	if (command.compare("ADD") == 0)
	{
		first = get_info("Frist Name: ");
		last = get_info("Last Name: ");
		nick = get_info("Nick Name: ");
		phoneBook->command_add(first, last, nick);
	}
	else if (command.compare("SEARCH") == 0)
	{
		phoneBook->command_search();
	}
	else if (command.compare("EXIT") == 0)
	{
		*exit = 0;
	}
}

int main(void) 
{
    PhoneBook   phoneBooks;
    std::string command;
    int         exit_flag = 1;

    while (exit_flag)
    {
		std::cout << "COMMAND: ";
        std::cin >> command;
		process(&phoneBooks, command, &exit_flag);
    }
    return 0;
}