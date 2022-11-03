#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& cat);
		~Cat();

		Cat& operator=(const Cat& cat);
		virtual void makeSound(void) const;
};

#endif