#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog's constructor called." << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	this->_type = dog.getType();
	std::cout << "Dog's copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->_type = dog.getType();
		std::cout << "Dog's Copy assignment operator called." << std::endl;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << " : bowwow!" << std::endl;
}
