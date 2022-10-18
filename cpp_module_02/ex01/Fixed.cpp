#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits = 0;
}

Fixed &Fixed::operator=(Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = fixed.getRawBits();
	return (*this);
}

std::string &Fixed::operator<<(Fixed &fixed)
{
	
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->raw_bits = fixed.getRawBits();
}

Fixed::Fixed(const int raw_bits)
{
	this->raw_bits = raw_bits << this->fractional_bits;;
}

Fixed::Fixed(const float raw_bits)
{

	this->raw_bits = raw_bits << this->fractional_bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits >> this->fractional_bits);
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}