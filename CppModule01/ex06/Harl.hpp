#pragma once

#include <iostream>

class Harl
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	std::string _cmds[4];

public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};
