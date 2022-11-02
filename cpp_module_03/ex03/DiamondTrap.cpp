#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "DiamondTrap " << this->name << "'s constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->name = name;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "DiamondTrap " << this->name << "'s constructor called." << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
	this->name = diamondTrap.name;
	this->setName(diamondTrap.setName());
	this->setHitPoints(diamondTrap.setHitPoints());
	this->setAttackDamage(diamondTrap.setAttackDamage());
	this->setEnergyPoints(diamondTrap.setEnergyPoints());
	std::cout << "DiamondTrap " << this->name << "'s Copy constructor called." << std::endl;

}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << "'s destructor called." << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	this->name = diamondTrap.name;
	this->setName(diamondTrap.setName());
	this->setHitPoints(diamondTrap.setHitPoints());
	this->setAttackDamage(diamondTrap.setAttackDamage());
	this->setEnergyPoints(diamondTrap.setEnergyPoints());
	std::cout << "DiamondTrap " << this->name << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	
}