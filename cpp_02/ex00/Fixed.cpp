#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
    std::cout << "Copy constructor called\n";
    this->setRawBits(a.getRawBits());
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed &a)
{
    std::cout << "copy assignment operator called\n";
    if (this != &a)
        this->setRawBits(a.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

