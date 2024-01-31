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

};

std::ostream &	operator<<(std::ostream &o, Fixed const &tmp);
