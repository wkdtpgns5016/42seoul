#include "DiamondTrap.hpp"
#include <iostream>

int main( void ) {
	DiamondTrap A = DiamondTrap("A");
	DiamondTrap B = DiamondTrap("B");

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.highFivesGuys();
	A.whoAmI();
	return 0;
}