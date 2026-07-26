#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void    Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);
    std::cout << buffer;
}

Account::Account( int initial_deposit )
    : _accountIndex(0), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    if (!_nbAccounts)
        std::cout << SKY_BLUE"          Account created" << RESET << "\n";
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

void	Account::displayAccountsInfos( void )
{
    std::cout << SKY_BLUE"       Display accounts infos" << RESET << "\n";
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:"; 
    std::cout << _totalAmount << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals;
    std::cout << '\n';
}

void	Account::displayStatus( void ) const
{
    if (!_accountIndex)
        std::cout << SKY_BLUE"       Display accounts status" << RESET << "\n";
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:";
    std::cout << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit )
{
    if (!_accountIndex)
        std::cout << SKY_BLUE"           make deposit" << RESET << "\n";
    int prev_amount = _amount;
    _displayTimestamp();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << "index:" << _accountIndex << ";p_amount:" << prev_amount;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:";
    std::cout << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (!_accountIndex)
        std::cout << SKY_BLUE"           make withdrawal" << RESET << "\n";
    int prev_amount = _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << prev_amount;
    if (withdrawal > _amount)
        return (std::cout << ";withdrawal:refused\n", 0);
    else
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:";
        std::cout << _nbWithdrawals << '\n';
    }
    return (1);
}

Account::~Account()
{
    if (!_accountIndex)
        std::cout << SKY_BLUE"          Account closed" << RESET << "\n";
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}