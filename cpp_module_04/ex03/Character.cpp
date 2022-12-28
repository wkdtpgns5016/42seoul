#include "Character.hpp"

Character::Character()
{
	this->_name = "name";
	for (int i=0; i<4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& character)
{
	this->_name = character.getName();
	for (int i=0; i<4; i++)
		this->_inventory[i] = character.getInventory(i);
}

Character::Character(std::string const & name)
{
	this->_name = name;
	for (int i=0; i<4; i++)
		this->_inventory[i] = NULL;
}
		
Character::~Character()
{
	for (int idx=0; idx<4; idx++)
	{
		if (this->_inventory[idx] != NULL)
			delete this->_inventory[idx];
	}
}

Character& Character::operator=(const Character& character)
{
	if (this != &character)
	{
		this->_name = character.getName();
		for (int i=0; i<4; i++)
			this->_inventory[i] = character.getInventory(i);
	}
	return (*this);
}

AMateria* Character::getInventory(int idx) const
{
	return (this->_inventory[idx]);
}

int Character::getIndexInventory() const
{
	int idx = 0;
	for (idx=0; idx<4; idx++)
	{
		if (this->_inventory[idx] == NULL)
			break ;
	}
	return (idx);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	const int idx = getIndexInventory();
	if (idx < 4)
		this->_inventory[idx] = m;
}

void Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
}