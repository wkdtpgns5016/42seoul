#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

	public:
		ScavTrap();
		ScavTrap(const ScavTrap& scavTrap);
		ScavTrap(std::string name);
		ScavTrap &operator=(ScavTrap &scavTrap);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate(void);
};

#endif