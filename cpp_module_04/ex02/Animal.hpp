#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& animal);
		virtual ~Animal();

		Animal& operator=(const Animal& animal);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif