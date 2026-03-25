#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	private:
		int 				fixedPoint;
		static const int	fractionalBits = 8;

	public:
		Fixed 			 ();
		Fixed 			 (const Fixed &src);
		Fixed& operator= (const Fixed &src);
		Fixed			 (const int nbr);
		Fixed  			 (const float nbr);

		~Fixed ();

		int getRawBits  (void) const;
		void setRawBits (int const raw);
		float toFloat   (void) const;
		int toInt       (void) const;

		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

		bool operator== (const Fixed &b) const;
		bool operator<  (const Fixed &b) const;
		bool operator>  (const Fixed &b) const;
		bool operator<= (const Fixed &b) const;
		bool operator>= (const Fixed &b) const;
		bool operator!= (const Fixed &b) const;

		Fixed operator+ (const Fixed &b) const;
		Fixed operator- (const Fixed &b) const;
		Fixed operator* (const Fixed &b) const;
		Fixed operator/ (const Fixed &b) const;

		Fixed& operator++ (void);
		Fixed& operator-- (void);
		Fixed operator++ (int);
		Fixed operator-- (int);
		
};

#endif