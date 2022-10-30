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

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->raw_bits = fixed.getRawBits();
}

Fixed::Fixed(const int raw_bits)
{
	this->raw_bits = raw_bits;
}

Fixed::Fixed(const float raw_bits)
{
	this->raw_bits = static_cast<int>(roundf(this->raw_bits * (1 << this->fractional_bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}


float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->raw_bits) / (1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->raw_bits >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	return (o << f.toFloat());
}
