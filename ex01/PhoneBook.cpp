/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:14:06 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 21:36:25 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isdigit;
using std::setw;        //Set field width     << std::setw(10); <=>  width = 10
using std::stringstream;



PhoneBook::PhoneBook(void) : _number(0) {}

PhoneBook::~PhoneBook(void) {cout << "Destruction PhoneBook" << endl;};

void PhoneBook::Add(void) {
    int i = _number++ % 8;
    _contacts[i].ChangeContact();
    cout << endl;
}

static int is_number(const string num) {
    for (size_t i = 0; i < num.length(); i++)
        if (!isdigit(num[i]))
            return 0;

    return 1;
}

void PhoneBook::SearchContact(void) const {
    int i;
    string idx;

    cout << "+----------+----------+----------+----------+" << endl;
    cout << "|     index|first name| last name|  nickname|" << endl;
    cout << "+----------+----------+----------+----------+" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "|";
        cout << setw(10) << i + 1 << "|";
        cout << setw(10) << _contacts[i].get_first_name_short() << "|";
        cout << setw(10) << _contacts[i].get_last_name_short() << "|";
        cout << setw(10) << _contacts[i].get_nickname_short() << "|" << endl;
        cout << "+----------+----------+----------+----------+" << endl;
    }

    cout << endl;
    i = -1;

    while (i != 0) {
        cout << "Contact [1-8, 0 to exit]: ";
        getline(cin, idx);

        if (cin.eof() || idx == "exit")
            break;

        if (idx.empty() || !is_number(idx))
            continue;

        stringstream tmp;       // on fait un cast comme ATOI dans ces 3 lignes
        tmp << idx;         // flux d'insertio dans tmp
        tmp >> i;           // flux d'extraction de tmp

        if (i >= 1 && i <= 8) {
            cout << "First Name: " << _contacts[i - 1].get_first_name() << endl;
            cout << "Last Name: " << _contacts[i - 1].get_last_name() << endl;
            cout << "Nickname: " << _contacts[i - 1].get_nickname() << endl;
            cout << "Phone Number: " << _contacts[i - 1].get_phone()  << endl;
            cout << "Darkest Secret: " << _contacts[i - 1].get_darkest_secret() << endl;
            cout << endl;
        }
    }
}
