#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->value = 0;
}

Fixed::Fixed( int const n )
{
	
}

Fixed::Fixed( float const n )
{

}

Fixed::Fixed( Fixed &tmp )
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