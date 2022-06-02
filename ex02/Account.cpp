#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
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

int main()
{}
