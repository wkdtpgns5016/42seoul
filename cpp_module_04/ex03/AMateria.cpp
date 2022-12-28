#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "type";
}

AMateria::AMateria(const AMateria& aMateria)
{
	this->_type = aMateria.getType();
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::~AMateria()
{

}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
	if (this != &aMateria)
	{
		this->_type = aMateria.getType();
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria use function. *" << target.getName();
}
