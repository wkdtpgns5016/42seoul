#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << this->name << "'s constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << "'s destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit_points > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take "<< this->attack_damage << " points of damage!" << std::endl;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " be repaired "<< amount << " points!" << std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
}