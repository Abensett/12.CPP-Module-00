#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructeur pour chacune des valeurs
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "created" << endl;
}
// Destructeur
Account::~Account(void) {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "closed" << endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// We display time stamps then all the infos
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << ";";
    cout << "total:" << _totalAmount << ";";
    cout << "deposits:" << _totalNbDeposits << ";";
    cout << "withdrawals:" << _totalNbWithdrawals << endl;
}
// Lors d'un depot: affiche time stamp then amount
void Account::makeDeposit(int deposit) {
    _totalAmount += deposit;
    ++_totalNbDeposits;
    _amount += deposit;
    ++_nbDeposits;
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << _amount - deposit << ";";
    cout << "deposit:" << deposit << ";";
    cout << "amount:" << _amount << ";";
    cout << "nb_deposits:" << _nbDeposits << endl;
}

// Check if withdral < amount if true -> accepted else refused
bool Account::makeWithdrawal(int withdrawal) {
    bool success = withdrawal <= _amount;
    _displayTimestamp();

    if (success) {
        _totalAmount -= withdrawal;
        ++_totalNbWithdrawals;
        _amount -= withdrawal;
        ++_nbWithdrawals;
        cout << "index:" << _accountIndex << ";";
        cout << "p_amount:" << _amount + withdrawal << ";";
        cout << "withdrawal:" << withdrawal << ";";
        cout << "amount:" << _amount << ";";
        cout << "nb_withdrawals:" << _nbDeposits << endl;
    } else {
        cout << "index:" << _accountIndex << ";";
        cout << "p_amount:" << _amount << ";";
        cout << "withdrawal:refused" << endl;
    }

    return success;
}

int Account::checkAmount(void) const {
    return _amount;
}
// Display the status of the account
void Account::displayStatus(void) const {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "deposits:" << _nbDeposits << ";";
    cout << "withdrawals:" << _nbWithdrawals << endl;
}

/*  time turn time_t pointer into time since 1970
    tm = struct containing 9 members : tm_sec, tm_min ...
   	localtime -> turn struct time_t  into struct tm
	*/
void Account::_displayTimestamp( void )
{
	char time_stamp[18];
	time_t now;
	struct tm time_structure;

	time(&now);
	localtime_r(&now, &time_structure);
	strftime(time_stamp, sizeof(time_stamp), "[%Y%m%d_%H%M%S]", &time_structure);
	cout << time_stamp << " ";
}
