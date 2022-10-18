#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "DEBUG" << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING" << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR" << std::endl;
}

Harl::Harl()
{
	this->msg_level[0] = "debug";
	this->msg_level[1] = "info";
	this->msg_level[2] = "warning";
	this->msg_level[3] = "error";
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
	(this->*f[idx])();
}