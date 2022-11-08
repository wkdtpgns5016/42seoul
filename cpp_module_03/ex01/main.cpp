#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	ScavTrap A = ScavTrap("A");
	ScavTrap B = ScavTrap("B");

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.attack("B");
	A.guardGate();
	
	return 0;
}