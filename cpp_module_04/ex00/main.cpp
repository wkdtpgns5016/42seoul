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

	j->makeSound();
	i->makeSound(); //will output the cat sound! 
	meta->makeSound();

	std::cout << "==========================================" << std::endl; 
	const WrongAnimal* k = new WrongCat();
	k->makeSound();
	const WrongCat* k2 = new WrongCat();
	k2->makeSound();

	std::cout << "==========================================" << std::endl; 
	delete meta;
	delete j;
	delete i;
	delete k;
	delete k2;
	return 0;
}
