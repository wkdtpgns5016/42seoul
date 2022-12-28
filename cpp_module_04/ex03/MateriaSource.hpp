#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _aMateria[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& materiaSource);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& materiaSource);

		AMateria* const & getAMateria(int idx) const;
		virtual void learnMateria(AMateria* aMateria);
		virtual AMateria* createMateria(std::string const & type);

		int getIndexMateria() const;
};

#endif