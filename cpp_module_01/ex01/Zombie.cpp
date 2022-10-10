#include "Zombie.hpp"

void	Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
	this->setName(name);
}

Zombie::~Zombie() {
	std::cout << this->name << ": is disapper." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
