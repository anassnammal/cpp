#pragma once
 
#include <iostream>
#include <cmath>

class Fixed
{
	int	value;

	static int const f = 8;

public:

	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const &tmp );
	~Fixed( void );

	Fixed &	operator=(Fixed const &tmp);

	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;

	bool	operator>(Fixed const & r) const;
	bool	operator<(Fixed const & r) const;
	bool	operator>=(Fixed const & r) const;
	bool	operator<=(Fixed const & r) const;
	bool	operator==(Fixed const & r) const;
	bool	operator!=(Fixed const & r) const;

	Fixed	operator+(Fixed const & r) const;
	Fixed	operator-(Fixed const & r) const;
	Fixed	operator*(Fixed const & r) const;
	Fixed	operator/(Fixed const & r) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed &	operator++(void);
	Fixed &	operator--(void);
	

	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed const &min(Fixed const &f1, Fixed const &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static Fixed const &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &	operator<<(std::ostream &o, Fixed const &tmp);
