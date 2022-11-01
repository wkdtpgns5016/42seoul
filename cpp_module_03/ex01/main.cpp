#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	 A = ClapTrap("A");
	ClapTrap B = ClapTrap("B");

	A.setAttackDamage(5);
	A.attack("B");
	B.takeDamage(5);
	B.setAttackDamage(3);
	B.attack("A");
	A.takeDamage(3);
	A.attack("B");
	B.takeDamage(5);
	
	B.attack("A");
	return 0;
}