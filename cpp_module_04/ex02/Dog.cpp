#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog's constructor called." << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	this->_type = dog.getType();
	this->_brain = new Brain(*dog._brain);
	std::cout << "Dog's copy constructor called." << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog's destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	this->_type = dog.getType();
	this->_brain = new Brain(*dog._brain);
	std::cout << "Dog's Copy assignment operator called." << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->_type << " : bowwow!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->_brain);
}
