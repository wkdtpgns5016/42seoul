#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << "DiamondTrap " << this->name << "'s constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->name = name;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	std::cout << "DiamondTrap " << this->name << "'s constructor called." << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
	this->name = diamondTrap.name;
	this->setName(diamondTrap.getName());
	this->setHitPoints(diamondTrap.getHitPoints());
	this->setAttackDamage(diamondTrap.getAttackDamage());
	this->setEnergyPoints(diamondTrap.getEnergyPoints());
	std::cout << "DiamondTrap " << this->name << "'s Copy constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << "'s destructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	this->name = diamondTrap.name;
	this->setName(diamondTrap.getName());
	this->setHitPoints(diamondTrap.getHitPoints());
	this->setAttackDamage(diamondTrap.getAttackDamage());
	this->setEnergyPoints(diamondTrap.getEnergyPoints());
	std::cout << "DiamondTrap " << this->name << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->name << "'s ClapTrap name is " << this->getName() << std::endl;
}