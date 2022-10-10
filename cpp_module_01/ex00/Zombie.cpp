#include "Zombie.hpp"

void	Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::Zombie() {
	this->setName(NULL);
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
