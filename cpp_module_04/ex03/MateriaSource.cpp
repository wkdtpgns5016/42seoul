#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx=0; idx<4; idx++)
		this->_aMateria[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	for (int idx=0; idx<4; idx++)
		this->_aMateria[idx] = materiaSource.getAMateria(idx);
}

MateriaSource::~MateriaSource()
{
	for (int idx=0; idx<4; idx++)
	{
		if (this->_aMateria[idx] != NULL)
			delete this->_aMateria[idx];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	for (int idx=0; idx<4; idx++)
		this->_aMateria[idx] = materiaSource.getAMateria(idx);
	return (*this);
}

AMateria* const & MateriaSource::getAMateria(int idx) const
{
	return (this->_aMateria[idx]);
}

void MateriaSource::learnMateria(AMateria* aMateria)
{
	int idx = getIndexMateria();
	if (idx < 4)
		this->_aMateria[idx] = aMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int idx=0; idx<4; idx++)
	{
		if (type.compare(this->_aMateria[idx]->getType()) == 0)
			return (this->_aMateria[idx]->clone());
	}
	return (0);
}

int MateriaSource::getIndexMateria() const
{
	int idx = 0;
	for (idx=0; idx<4; idx++)
	{
		if (this->_aMateria[idx] == NULL)
			break ;
	}
	return (idx);
}
