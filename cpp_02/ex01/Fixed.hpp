#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int fixed_point;
        static const int fractbits_value = 8;
    public:
        Fixed();
        Fixed(const int _int);
        Fixed(float _float);
        Fixed(const Fixed &a);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed &a);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};

std::ostream& operator<<(std::ostream& _cout, const Fixed& obj);

#endif