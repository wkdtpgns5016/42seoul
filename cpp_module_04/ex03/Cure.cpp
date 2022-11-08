#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure& cure)
{
	this->_type = cure.getType();
}

Cure::~Cure()
{

}

Cure& Cure::operator=(const Cure& cure)
{
	this->_type = cure.getType();
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* aMateria = new Cure();
	return (aMateria);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}

