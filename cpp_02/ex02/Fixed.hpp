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
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        static Fixed& min(Fixed &a, Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
        Fixed operator++(int);
        Fixed &operator++();
        Fixed operator--(int);
        Fixed &operator--();
        Fixed operator+(const Fixed &b) const;
        Fixed operator-(const Fixed &b) const;
        Fixed operator*(const Fixed &b) const;
        Fixed operator/(const Fixed &b) const;
        ~Fixed();
};

std::ostream& operator<<(std::ostream& _cout, const Fixed& obj);

#endif