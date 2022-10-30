#include "Fixed.hpp"

Fixed::Fixed()
{
	this->raw_bits = 0;
}

Fixed::Fixed(const Fixed &fixed) : raw_bits(fixed.getRawBits())
{
}

Fixed::Fixed(const int raw_bits) : raw_bits(raw_bits << this->fractional_bits)
{
}

Fixed::Fixed(const float raw_bits) : raw_bits(static_cast<int>(roundf(raw_bits * (1 << this->fractional_bits))))
{
}

Fixed::~Fixed()
{
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
	this->raw_bits = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->raw_bits > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->raw_bits < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->raw_bits >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->raw_bits <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->raw_bits == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->raw_bits != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed temp(this->toFloat() + fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed temp(this->toFloat() - fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed temp(this->toFloat() * fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	++this->raw_bits;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	--this->raw_bits;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

const Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b); 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a > b ? b : a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a > b ? b : a);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	return (o << fixed.toFloat());
}
