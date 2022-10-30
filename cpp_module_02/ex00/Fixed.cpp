#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << "\n";
	this->raw_bits = 0;
}

Fixed::Fixed(const Fixed &fixed) : raw_bits(fixed.getRawBits())
{
	std::cout << "Copy constructor called" << "\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits(void) const
{
	return (this->raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << "\n";
	this->raw_bits = fixed.getRawBits();
	return (*this);
}
