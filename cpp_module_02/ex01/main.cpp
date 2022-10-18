#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	std::cout <<"-----------a------------------------" << std::endl;
	Fixed a;
	std::cout <<"-----------b ( a )------------------" << std::endl;
	Fixed b( a );
	std::cout <<"-----------c------------------------" << std::endl;
	Fixed c;
	std::cout <<"-----------c = b--------------------" << std::endl;
	c = b;
	std::cout <<"------------------------------------" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout <<"------------------------------------" << std::endl;
	return 0;
}