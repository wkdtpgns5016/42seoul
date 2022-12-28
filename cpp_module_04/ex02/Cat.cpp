#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat's constructor called." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
	this->_type = cat.getType();
	this->_brain = new Brain(*cat._brain);
	std::cout << "Cat's copy constructor called." << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat's destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->_type = cat.getType();
		this->_brain = new Brain(*cat._brain);
		std::cout << "Cat's Copy assignment operator called." << std::endl;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << " : ......" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (this->_brain);
}
