#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice& ice)
{
	this->_type = ice.getType();
}

Ice::~Ice()
{

}

Ice& Ice::operator=(const Ice& ice)
{
	this->_type = ice.getType();
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* aMateria = new Ice();
	return (aMateria);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
}
