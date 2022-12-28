#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];

	public:
		Character();
		Character(const Character& character);
		Character(std::string const & name);
		~Character();
		Character& operator=(const Character& character);

		AMateria* getInventory(int idx) const;
		int getIndexInventory() const;
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif