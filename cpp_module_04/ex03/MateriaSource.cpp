#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_aMateria = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	this->_aMateria = materiaSource.getAMateria();
}

MateriaSource::~MateriaSource()
{
	
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	this->_aMateria = materiaSource.getAMateria();
	return (*this);
}

AMateria* const & MateriaSource::getAMateria() const
{
	return (this->_aMateria);
}

void MateriaSource::learnMateria(AMateria* aMateria)
{
	this->_aMateria = aMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type.compare(this->_aMateria->getType()) == 0)
		return (this->_aMateria->clone());
	else
		return (0);
}