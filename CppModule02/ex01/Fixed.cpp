#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	this->value = 0;
}

Fixed::Fixed( int const n )
{
	int	s;

	s = 1;
	if (n < 0)
		s = -1;
	this->value = (((n * s) << Fixed::f) * s);
}

Fixed::Fixed( float const n ) : value(std::roundf(n * (1 << Fixed::f)))
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

float	Fixed::toFloat( void ) const
{
	return (this->value / (1 << Fixed::f));
}

int		Fixed::toInt( void ) const
{
	int	s;

	s = 1;
	if (this->value < 0)
		s = -1;
	return (((this->value * s) >> 8) * s);
}

std::ostream &	Fixed::operator<<(std::ostream &o)
{
	o << this->toFloat();
}