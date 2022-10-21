#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	this->msg_level[0] = "DEBUG";
	this->msg_level[1] = "INFO";
	this->msg_level[2] = "WARNING";
	this->msg_level[3] = "ERROR";
}

int	Harl::get_index_level(std::string level)
{
	int i;

	for (i=0; i<4; i++)
	{
		if (this->msg_level[i].compare(level) == 0)
			break;
	}
	return (i);
}

void Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void);
	int		idx;

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	idx = get_index_level(level);
	if (idx >= 4)
		return ;
	while (idx < 4)
	{
		(this->*f[idx++])();
		std::cout << std::endl;
	}
}