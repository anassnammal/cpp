#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) _amount(initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
}
// public non member funcs
static int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

static int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

static int	Account::getNbDeposits( void )
{
	return (Account::_nbDeposits);
}

static int	Account::getNbWithdrawals( void )
{
	return (Account::_nbWithdrawals);
}

static void	Account::displayAccountsInfos( void )
{
	std::cout << Account::getNbAccounts() << std::endl;
	std::cout << Account::getTotalAmount() << std::endl;
	std::cout << Account::getNbDeposits() << std::endl;
	std::cout << Account::getNbWithdrawals() << std::endl;
}
// public member funcs
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) 
{
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	
}
// private non member funcs
static void	Account::_displayTimestamp( void )
{
	std::time_t now;
}