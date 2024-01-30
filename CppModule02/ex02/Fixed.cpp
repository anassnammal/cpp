#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	this->value = 0;
}

Fixed::Fixed( int const n ) : value(n * (1 << Fixed::f))
{

}

Fixed::Fixed( float const n ) : value((int)::roundf(n * (1 << Fixed::f)))
{

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

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << Fixed::f));
}

int		Fixed::toInt( void ) const
{
	return (this->value / (1 << Fixed::f));
}

std::ostream &	operator<<(std::ostream &o, Fixed const &tmp)
{
	o << tmp.toFloat();
	return (o);
}
