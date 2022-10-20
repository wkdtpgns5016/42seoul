#include "PhoneBook.hpp"

std::string get_info(std::string info)
{
	std::string str;
	
	while (1)
	{
		std::cout << info;
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (str.empty())
			continue ;
		else break ;
	}
	return (str);
}

int	process(PhoneBook *phoneBook, std::string command, int *exit)
{
	std::string first;
	std::string last;
	std::string nick;
	std::string phone;
	std::string secret;

	if (command.compare("ADD") == 0)
	{
		first = get_info("Frist Name: ");
		if (first.empty())
			return 1;
		last = get_info("Last Name: ");
		if (last.empty())
			return 1;
		nick = get_info("Nick Name: ");
		if (nick.empty())
			return 1;
		phone = get_info("Phone Number: ");
		if (phone.empty())
			return 1;
		secret = get_info("Darkest Secret: ");
		if (secret.empty())
			return 1;
		return phoneBook->command_add(first, last, nick, phone, secret);
	}
	else if (command.compare("SEARCH") == 0)
	{
		return phoneBook->command_search();
	}
	else if (command.compare("EXIT") == 0)
	{
		*exit = 0;
		return 0;
	}
	return 0;
}

int main(void) 
{
    PhoneBook   phoneBooks;
    std::string command;
    int         exit_flag = 1;

    while (exit_flag)
    {
		std::cout << "COMMAND: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (process(&phoneBooks, command, &exit_flag))
		{
			std::cout << std::endl;
			break ;
		}
    }
    return 0;
}