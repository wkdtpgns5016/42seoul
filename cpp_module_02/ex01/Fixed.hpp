#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int raw_bits;
		static const int fractional_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int raw_bits);
		Fixed(const float raw_bits);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed & operator=(const Fixed &fixed);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif