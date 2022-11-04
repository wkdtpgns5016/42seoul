#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wrongAnimal);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif