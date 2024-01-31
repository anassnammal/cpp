#include "Fixed.hpp"

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

bool	Fixed::operator>(Fixed const & r) const
{
	return (this->toFloat() > r.toFloat());
}

bool	Fixed::operator<(Fixed const & r) const
{
	return (this->toFloat() < r.toFloat());
}

bool	Fixed::operator>=(Fixed const & r) const
{
	return (this->toFloat() >= r.toFloat());
}

bool	Fixed::operator<=(Fixed const & r) const
{
	return (this->toFloat() <= r.toFloat());
}

bool	Fixed::operator==(Fixed const & r) const
{
	return (this->toFloat() == r.toFloat());
}

bool	Fixed::operator!=(Fixed const & r) const
{
	return (this->toFloat() != r.toFloat());
}

Fixed	Fixed::operator+(Fixed const & r) const
{
	Fixed res;

	res.setRawBits(this->value + r.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const & r) const
{
	Fixed res;

	res.setRawBits(this->value - r.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(Fixed const & r) const
{
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & r) const
{
	return (Fixed(this->toFloat() / r.toFloat()));
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

Fixed &	Fixed::operator++(void)
{
	this->value++;
	return (*this);	
}

Fixed &	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed const & Fixed::min(Fixed const &f1, Fixed const &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

Fixed const & Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return ((f1 > f2) ? f1 : f2);
}
