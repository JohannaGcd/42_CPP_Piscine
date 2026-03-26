#ifndef FIXED_H
# define FIXED_H

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixedPoint;
		static const int fractionalBits = 8;

	public:
		Fixed ();
		Fixed (const Fixed& src);
		Fixed& operator= (const Fixed& src);
		Fixed (const int nbr);
		Fixed(const float flt);

		~Fixed();

		int 	getRawBits (void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int		toInt (void) const;

		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif