#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << "'s constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
	this->setName(fragTrap.getName());
	this->setHitPoints(fragTrap.getHitPoints());
	this->setEnergyPoints(fragTrap.getEnergyPoints());
	this->setAttackDamage(fragTrap.getAttackDamage());
	std::cout << "FragTrap " << this->getName() << "'s constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << "'s constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << "'s destructor called." << std::endl;
}
FragTrap &FragTrap::operator=(FragTrap &fragTrap)
{
	this->setName(fragTrap.getName());
	this->setHitPoints(fragTrap.getHitPoints());
	this->setEnergyPoints(fragTrap.getEnergyPoints());
	this->setAttackDamage(fragTrap.getAttackDamage());
	std::cout << "FragTrap " << this->getName() << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " request positive high fives!" << std::endl;
}