#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "==========================================" << std::endl; 
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 

	i->makeSound(); //will output the cat sound! 
	j->makeSound();
	meta->makeSound();

	std::cout << "==========================================" << std::endl; 
	const WrongAnimal* k = new WrongCat();
	k->makeSound();

	std::cout << "==========================================" << std::endl; 
	delete meta;
	delete j;
	delete i;
	delete k;
	return 0;
}
