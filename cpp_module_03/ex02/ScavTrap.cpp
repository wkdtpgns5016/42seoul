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
	this->setName(scavTrap.getName());
	this->setHitPoints(scavTrap.getHitPoints());
	this->setEnergyPoints(scavTrap.getEnergyPoints());
	this->setAttackDamage(scavTrap.getAttackDamage());
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
	this->setName(scavTrap.getName());
	this->setHitPoints(scavTrap.getHitPoints());
	this->setEnergyPoints(scavTrap.getEnergyPoints());
	this->setAttackDamage(scavTrap.getAttackDamage());
	std::cout << "ScavTrap " << this->getName() << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << "is use guardGate." << std::endl;
}