/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:14:06 by abensett          #+#    #+#             */
/*   Updated: 2022/04/30 23:54:50 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline; 
using std::isdigit;
using std::setw;        //Set field width     << std::setw(10); <=>  width = 10
using std::stoi;        //stoi = string to int



Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""),
        _phone(""), _darkest_secret("") {}

Contact::~Contact(void) {cout << "Destruction Contact "<<_first_name << endl;};

string Contact::get_first_name ( void ) const {
    return _first_name;
}

string Contact::get_last_name(void) const {
    return _last_name;
}

string Contact::get_nickname(void) const {
    return _nickname;
}

string Contact::get_phone(void) const {
    return _phone;
}

string Contact::get_darkest_secret(void) const {
    return _darkest_secret;
}

string Contact::get_first_name_short(void) const {
    if (_first_name.length() > 10)
        return (_first_name.substr(0, 9) + ".");

    return _first_name;
}

string Contact::get_last_name_short(void) const {
    if (_last_name.length() > 10)
        return (_last_name.substr(0, 9) + ".");

    return _last_name;
}

string Contact::get_nickname_short(void) const {
    if (_nickname.length() > 10)
        return (_nickname.substr(0, 9) + ".");

    return _nickname;
}

static void get_input(string *field, const string prompt) {
    while (field->empty()) {
        cout << prompt << ": ";         //display prompt :
        getline(cin, *field);           //readline

        if (cin.eof())                  //end of the file
            break;
    }
}

void Contact::ChangeContact (void)
{
    _first_name.clear();
    get_input(&_first_name, "First Name");
    _last_name.clear();
    get_input(&_last_name, "Last Name");
    _nickname.clear();
    get_input(&_nickname, "Nickname");
    _phone.clear();
    get_input(&_phone, "Phone Number");
    _darkest_secret.clear();
    get_input(&_darkest_secret, "Darkest Secret");
}

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

        i = stoi(idx);

        if (i >= 1 && i <= 8) {
            cout << "First Name: " << _contacts[i - 1].get_first_name() << endl;
            cout << "Last Name: " << _contacts[i - 1].get_last_name() << endl;
            cout << "Nickname: " << _contacts[i - 1].get_nickname() << endl;
            cout << "Phone Number: " << _contacts[i - 1].get_phone()
                    << endl;
            cout << "Darkest Secret: "
                    << _contacts[i - 1].get_darkest_secret() << endl;
            cout << endl;
        }
    }
}