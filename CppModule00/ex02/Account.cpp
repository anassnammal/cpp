#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex << ';';
	std::cout << "amount:";
	std::cout << this->_amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex << ';';
	std::cout << "amount:";
	std::cout << this->_amount << ';';
	std::cout << "closed" << std::endl;
}
// public non member funcs
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';';
	std::cout << "total:" << Account::getTotalAmount() << ';';
	std::cout << "deposits:" << Account::getNbDeposits() << ';';
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
// public member funcs
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex << ';';
	std::cout << "p_amount:";
	std::cout << this->_amount << ';';
	std::cout << "deposit:";
	std::cout << deposit << ';';
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:";
	std::cout << this->_amount << ';';
	std::cout << "nb_deposits:";\
	std::cout << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) 
{
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex << ';';
	std::cout << "p_amount:";
	std::cout << this->_amount << ';';
	std::cout << "withdrawal:";
	if (this->checkAmount() >= withdrawal)
	{
		std::cout << withdrawal << ';';
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << "amount:";
		std::cout << this->_amount << ';';
		std::cout << "nb_withdrawals:";\
		std::cout << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
		std::cout << "refused" << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex << ';';
	std::cout << "amount:";
	std::cout << this->_amount << ';';
	std::cout << "deposits:";
	std::cout << this->_nbDeposits << ';';
	std::cout << "withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;

}
// private non member funcs
void	Account::_displayTimestamp( void )
{
	std::time_t rawtime;
	std::tm * timeinfo;
	char buffer[19];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}
