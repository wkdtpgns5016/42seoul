#include "Weapon.hpp"

const std::stirng &Weapon::getType() {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}