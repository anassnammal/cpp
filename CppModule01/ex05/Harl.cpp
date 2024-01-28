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
	std::cout << "wellcome to @debug level!";
}

void	Harl::info(void)
{
	std::cout << "hey this is @info level!";
}

void	Harl::warning(void)
{
	std::cout << "pay attention, this is @warning level!";
}

void	Harl::error(void)
{
	std::cout << "watch-out this is @error level!";
}

void	Harl::complain(std::string level)
{
	int _level;

	_level = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_cmds[i] == level)
		{
			_level = i;
			(this->*_run[_level])();
		}
	}
	if (_level < 0)
		std::cout << "Invalid level!. ex <DEBUG>/<INFO>/<WARNING>/<ERROR>";
	std::cout << std::endl;
}
