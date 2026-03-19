#ifndef FIXED_H
# define FIXED_H

#include <string>
#include <iostream>

class Fixed {

    private:
        int fixedPoint;
        static const int fractionalBits = 8;

    public:
        Fixed ();
        Fixed (const Fixed &oldFixed);
        Fixed& operator= (const Fixed& other);
        ~Fixed ();

        int     getRawBits (void) const;
        void    setRawBits (int const raw);
};

#endif