#include "Harl.hpp"
#include <algorithm>


Harl::Harl(void)
{
	this->_run[0] = &Harl::debug;
	this->_run[1] = &Harl::info;
	this->_run[2] = &Harl::warning;
	this->_run[3] = &Harl::error;

	this->_cmds[0] = "DEBUG";
	this->_cmds[1] = "INFO";
	this->_cmds[2] = "WARNING";
	this->_cmds[3] = "ERROR";
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
	int l;

    l = std::find(this->_cmds.begin(), this->_cmds.end(), level);
    if (l >= 0 && l < 4)
	    this->*_run[l]();
}
