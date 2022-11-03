#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << "'s constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << "'s constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->_name = clapTrap.getName();
	this->_hitPoints = clapTrap.getHitPoints();
	this->_energyPoints = clapTrap.getEnergyPoints();
	this->_attackDamage = clapTrap.getAttackDamage();
	std::cout << "ClapTrap " << this->_name << "'s Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << "'s destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &clapTrap)
{
	this->_name = clapTrap.getName();
	this->_hitPoints = clapTrap.getHitPoints();
	this->_energyPoints = clapTrap.getEnergyPoints();
	this->_attackDamage = clapTrap.getAttackDamage();
	std::cout << "ClapTrap " << this->_name << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take "<< amount << " points of damage!" << std::endl;
	if (this->_hitPoints <= amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " be repaired "<< amount << " points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}

std::string ClapTrap::getName(void) const { return this->_name; }
int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
int ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }
int ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

void ClapTrap::setName(std::string const name) { this->_name = name; }
void ClapTrap::setHitPoints(unsigned int const hitPoints) { this->_hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int const energyPoints) { this->_energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(unsigned int const attackDamage) { this->_attackDamage = attackDamage; }