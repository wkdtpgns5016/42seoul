#include "Zombie.hpp"

int main(void) {
	Zombie	*zombie;
	Zombie	zzombie("zzombie");

	zombie = newZombie("zombie");
	randomChump("zzzombie");
	zombie->announce();
	zzombie.announce();
	delete zombie;
	return (0);
}