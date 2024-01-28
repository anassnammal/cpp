#include "Harl.hpp"
#include <algorithm>

Harl::Harl(void)
{
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
			_level = i;
	}
	switch (_level)
	{
	case 0:
		this->debug();
		std::cout << std::endl;
	case 1:
		this->info();
		std::cout << std::endl;
	case 2:
		this->warning();
		std::cout << std::endl;
	case 3:
		this->error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "Invalid level!. ex <DEBUG>/<INFO>/<WARNING>/<ERROR>";
		std::cout << std::endl;
	}
}
