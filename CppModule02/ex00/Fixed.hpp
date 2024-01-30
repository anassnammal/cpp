#pragma once

class Fixed
{
	int	value;

	static int const f = 0;

public:

	Fixed(void);
	Fixed(Fixed const &tmp);
	~Fixed(void);

	Fixed &	operator=(Fixed const &tmp);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

