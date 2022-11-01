#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << "'s constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
	this->setName(this->getName());
	this->setHitPoints(this->getHitPoints());
	this->setEnergyPoints(this->getEnergyPoints());
	this->setAttackDamage(this->getAttackDamage());
	std::cout << "ScavTrap " << this->getName() << "'s constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << "'s constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << "'s destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap &scavTrap)
{
	this->setName(this->getName());
	this->setHitPoints(this->getHitPoints());
	this->setEnergyPoints(this->getEnergyPoints());
	this->setAttackDamage(this->getAttackDamage());
	std::cout << "ScavTrap " << this->getName() << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << "is use guardGate." << std::endl;
}