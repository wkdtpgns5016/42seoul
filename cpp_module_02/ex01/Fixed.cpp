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

Fixed::Fixed(const int raw_bits) : raw_bits(raw_bits << this->fractional_bits)
{
	std::cout << "Int constructor called" << "\n";
}

Fixed::Fixed(const float raw_bits) : raw_bits(static_cast<int>(roundf(raw_bits * (1 << this->fractional_bits))))
{
	std::cout << "Float constructor called" << "\n";
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

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->raw_bits) / (1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->raw_bits >> this->fractional_bits);
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << "\n";
	this->raw_bits = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	return (o << fixed.toFloat());
}
