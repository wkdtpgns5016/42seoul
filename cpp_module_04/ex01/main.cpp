#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *meta[4];
	const Dog dogs[2];
	const Cat cats[2];

	std::cout << "=========================================" << std::endl;
	for (int i = 0; i < 2; i++)
		meta[i] = new Dog(dogs[i]);
	for (int i = 0; i < 2; i++)
		meta[i + 2] = new Cat(cats[i]);
	std::cout << "=========================================" << std::endl;
	std::cout << meta[0] << " " << &dogs[0] << std::endl;
	std::cout << meta[1] << " " << &dogs[1] << std::endl;
	std::cout << meta[2] << " " << &cats[0] << std::endl;
	std::cout << meta[3] << " " << &cats[1] << std::endl;
	std::cout << "=========================================" << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete meta[i];

	std::cout << "=========================================" << std::endl;

	dogs[0].getBrain()->setIdea(0, "I am Happy");
	std::cout << dogs[0].getType() << ": " << dogs[0].getBrain()->getIdea(0) << std::endl;

	std::cout << "=========================================" << std::endl;
	return 0;
}
