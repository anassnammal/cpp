#pragma once

#include <iostream>

class Harl
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	(Harl::*_run[4])(void);
public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};

Harl::Harl(void)
{
	this->_run[0] = &Harl::debug;
	this->_run[1] = &Harl::info;
	this->_run[2] = &Harl::warning;
	this->_run[3] = &Harl::error;
}

Harl::~Harl(void)
{

}

void	Harl::debug(void)
{
	std::cout << "@debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "@info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "@warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "@error" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	l = 
	this->_run[0]()
}