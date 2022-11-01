#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << "'s constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << "'s constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->name = clapTrap.getName();
	this->hitPoints = clapTrap.getHitPoints();
	this->energyPoints = clapTrap.getEnergyPoints();
	this->attackDamage = clapTrap.getAttackDamage();
	std::cout << "ClapTrap " << this->name << "'s Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << "'s destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &clapTrap)
{
	this->name = clapTrap.getName();
	this->hitPoints = clapTrap.getHitPoints();
	this->energyPoints = clapTrap.getEnergyPoints();
	this->attackDamage = clapTrap.getAttackDamage();
	std::cout << "ClapTrap " << this->name << "'s Copy assignment operator called." << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take "<< amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " be repaired "<< amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}

std::string ClapTrap::getName(void) const { return this->name; }
int ClapTrap::getHitPoints(void) const { return this->hitPoints; }
int ClapTrap::getEnergyPoints(void) const { return this->energyPoints; }
int ClapTrap::getAttackDamage(void) const { return this->attackDamage; }

void ClapTrap::setName(std::string const name) { this->name = name; }
void ClapTrap::setHitPoints(int const hitPoints) { this->hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(int const energyPoints) { this->energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(int const attackDamage) { this->attackDamage = attackDamage; }