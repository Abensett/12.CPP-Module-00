/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:25:09 by abensett          #+#    #+#             */
/*   Updated: 2022/05/01 05:29:20 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::getline;
using std::string;


int main(){
    string entry;
    PhoneBook MyPhoneBook;

    while (1)
    {
        cout<<"ADD, SEARCH or EXIT ?";
        getline(cin, entry);                // Car cin >> entry only grabs the first word the rest is in the input stream
        if (cin.eof() || entry == "EXIT")
            break;
        if (entry == "ADD")
            MyPhoneBook.Add();
        else if (entry == "SEARCH")
            MyPhoneBook.SearchContact();
    }
    return 0;
}