#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
	FragTrap A = FragTrap("A");
	FragTrap B = FragTrap("B");

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.highFivesGuys();
	return 0;
}