#include "Account.hpp"
#include "iostream"


Account::Account( int initial_deposit ) {

    _amount = initial_deposit;
    
};

void Account::displayAccountsInfos( void ) {

    std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";deposits:" <<  _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl ;

};

void    Account::displayStatus( void ) const {

    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl ;
    
};


int		Account::checkAmount( void ) const {

    return _amount;

};

void    Account::makeDeposit( int deposit ) {

    _totalAmount = _totalAmount + deposit;
    _totalNbDeposits = _totalNbDeposits + 1;

};


bool    Account::makeWithdrawal( int withdrawal ) {

    _totalAmount = _totalAmount - withdrawal;
    _totalNbWithdrawals = _totalNbWithdrawals + 1;

};

