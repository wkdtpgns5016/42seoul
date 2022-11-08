#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's constructor called." << std::endl;

}

Animal::Animal(const Animal& animal) : _type(animal.getType())
{
	std::cout << "Animal's copy constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
	this->_type = animal.getType();
	std::cout << "Animal's Copy assignment operator called." << std::endl;
	return (*this);
}

std::string Animal::getType(void) const { return (this->_type); }
void Animal::setType(const std::string& type) { this->_type = type; }