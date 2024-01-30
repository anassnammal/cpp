#pragma once

class Fixed
{
	int	value;

	static int const f = 0;

public:

	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed &tmp );
	~Fixed( void );

	Fixed &	operator=(Fixed const &tmp);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

