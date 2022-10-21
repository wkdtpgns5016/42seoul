#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon() {

}

const std::string& Weapon::getType() {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}