#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap A = ClapTrap("A");
	ClapTrap B = ClapTrap("B");
	A.attack("B");
	B.takeDamage(10);
	B.attack("A");
	return 0;
}