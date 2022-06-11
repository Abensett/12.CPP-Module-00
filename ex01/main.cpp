/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:25:09 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 19:21:02 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::getline;
using std::string;

/* -getline is from the library string -> self-explanatory equivalent to readline in C*/

int main(){
	string entry;
	PhoneBook MyPhoneBook;

	while (1)
	{
		cout<<"ADD, SEARCH or EXIT ?";
		getline(cin, entry);                // Car cin >> entry only grabs the first word the rest is in the input stream
		if (cin.eof() || entry == "EXIT")	// check end of file in case of ctrl+d
			break;
		if (entry == "ADD")
			MyPhoneBook.Add();
		else if (entry == "SEARCH")
			MyPhoneBook.SearchContact();
	}
	return 0;
}
