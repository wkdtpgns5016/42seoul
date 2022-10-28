#include "Zombie.hpp"

int main(void) {
	Zombie	*zombie;
	zombie = newZombie("zombie");
	zombie->announce();
	delete zombie;

	Zombie	zombie1("zombie1");
	zombie1.announce();

	randomChump("zombie2");
	return (0);
}