#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();
		FragTrap &operator=(FragTrap &fragTrap);

		void highFivesGuys(void);
};

#endif