#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ) {

    _amount = initial_deposit;
    _nbDeposits = 0;
	_accountIndex = _nbAccounts;
	_nbWithdrawals = 0 ;
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl ;
};

Account::~Account ( void ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp ( void ) {

    std::time_t now = std::time(NULL);
    std::tm *info = std::localtime(&now);

    std::cout << "[" << std::put_time(info, "%Y%m%d_%H%M%S") << "] ";
}

void Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
};

void    Account::displayStatus( void ) const {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl ;
    
};

int		Account::checkAmount( void ) const {

    return _amount;

};

void    Account::makeDeposit( int deposit ) {

    int p_amount = _amount;
    _amount = _amount + deposit;
    _nbDeposits = 1;
    _totalAmount = _totalAmount + deposit;
    _totalNbDeposits = _totalNbDeposits + 1;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
};

bool    Account::makeWithdrawal( int withdrawal ) {

    int p_amount = _amount;

    if (_amount >= withdrawal) {
        _amount = _amount - withdrawal;
        _nbWithdrawals = 1;
        _totalAmount = _totalAmount - withdrawal;
        _totalNbWithdrawals = _totalNbWithdrawals + 1;

        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        
        return true;
    }
    else {
        _displayTimestamp();
        std::cout <<  "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << "refused" << std::endl;
        return false;
    }
};

