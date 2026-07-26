#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(a.fixed_point);
}

Fixed::Fixed(float _float)
{
    // std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(_float * (1 << fractbits_value));
}

Fixed::Fixed(const int _int)
{
    // std::cout << "Int constructor called" << std::endl;
    fixed_point = _int * (1 << fractbits_value);
}

int Fixed::toInt( void ) const
{
    return fixed_point / (1 << fractbits_value);
}

float Fixed::toFloat( void ) const
{
    return fixed_point / (float)(1 << fractbits_value);
}

int Fixed::getRawBits( void ) const
{
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed &a)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->setRawBits(a.fixed_point);
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->fixed_point > other.fixed_point;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->fixed_point < other.fixed_point;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->fixed_point != other.fixed_point;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed Fixed::operator+(const Fixed &b) const
{
    Fixed result;
    result.fixed_point = fixed_point + b.fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed &b) const
{
    Fixed result;
    result.fixed_point = fixed_point - b.fixed_point;
    return result;
}


Fixed Fixed::operator*(const Fixed &b) const
{
    Fixed result;
    result.fixed_point = (fixed_point * b.fixed_point) / (1 << fractbits_value);
    return result;
}


Fixed Fixed::operator/(const Fixed &b) const
{
    Fixed result;
    result.fixed_point = (fixed_point * (1 << fractbits_value)) / b.fixed_point;
    return result;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& _cout, const Fixed& obj)
{
    _cout << obj.toFloat();
    return _cout;
}

Fixed Fixed::operator++(int)
{
    Fixed copy = *this;
    fixed_point += 1;
    return copy;
}

Fixed &Fixed::operator++()
{
    fixed_point += 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copy = *this;
    fixed_point -= 1;
    return copy;
}

Fixed &Fixed::operator--()
{
    fixed_point -= 1;
    return *this;
}


Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

