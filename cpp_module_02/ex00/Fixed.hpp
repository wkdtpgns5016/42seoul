#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int raw_bits;
		static const int fractional_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator=(const Fixed &fixed);
};

#endif