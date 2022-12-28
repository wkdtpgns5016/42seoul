#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat's constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal()
{
	this->_type = wrongCat.getType();
	std::cout << "WrongCat's copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	if (this != &wrongCat)
	{
		this->_type = wrongCat.getType();
		std::cout << "WrongCat's Copy assignment operator called." << std::endl;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << this->_type << " : ......" << std::endl;
}
