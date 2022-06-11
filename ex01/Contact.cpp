/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:07:07 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 22:22:35 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isdigit;
using std::setw;        //Set field width     << std::setw(10); <=>  width = 10
using std::stringstream;


Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""),		// initialisation list
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
		return (_first_name.substr(0, 9) + "."); //return a sub string from 0 with a len of 9

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
	while (field->empty()) {			//check if empty return TRUE
		cout << prompt << ": ";         //display prompt :
		getline(cin, *field);           //readline

		if (cin.eof())                  //is end of the file?
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
