#pragma once
 
#include <iostream>
 
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


	// • The 6 comparison operators: >, <, >=, <=, == and !=
	Fixed
};

std::ostream &	operator<<(std::ostream &o, Fixed const &tmp);
