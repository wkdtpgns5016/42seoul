#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat's constructor called." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
	this->_type = cat.getType();
	std::cout << "Cat's copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	this->_type = cat.getType();
	std::cout << "Cat's Copy assignment operator called." << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << " : ......" << std::endl;
}
