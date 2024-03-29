#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->value = 0;
}

Fixed::Fixed( Fixed const &tmp )
{
	*this = tmp;
}

Fixed::~Fixed( void )
{

}

Fixed &	Fixed::operator=(Fixed const &tmp)
{
	this->value = tmp.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}