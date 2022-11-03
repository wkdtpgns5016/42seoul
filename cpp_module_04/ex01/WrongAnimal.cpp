#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's constructor called." << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) : _type(wrongAnimal.getType())
{
	std::cout << "WrongAnimal's copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	this->_type = wrongAnimal.getType();
	std::cout << "WrongAnimal's Copy assignment operator called." << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal's Sound." << std::endl;
}

std::string WrongAnimal::getType(void) const { return (this->_type); }
void WrongAnimal::setType(const std::string& type) { this->_type = type; }