/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:54:28 by abensett          #+#    #+#             */
/*   Updated: 2022/04/30 19:13:31 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using std::string;

class Contact {
public :
    Contact(void);                               //constructeur 
    ~Contact(void);                              //destructeur = procedures sans type de retour

    string get_first_name(void) const;           //fonction membre
    string get_last_name(void) const;            //le const empeche la modification de l'instance courante
    string get_nickname(void) const;             //There will never this->attribut = ...
    string get_phone(void) const;
    string get_darkest_secret(void) const;
    string get_first_name_short(void) const;
    string get_last_name_short(void) const;
    string  get_nickname_short(void) const;
    void ChangeContact(void);

private :
    string _first_name;
    string _last_name;
    string _nickname;
    string _phone;
    string _darkest_secret;
};

class PhoneBook {
public :
    PhoneBook(void);                             //constructeur 
    ~PhoneBook(void);                            //destructeur = procedures sans type de retour

    void Add(void);                              // Not const because it modifies phonebook
    void SearchContact(void) const;

private:
    int        _number;
    Contact    _contacts[8];                      //_variable_privé
    
};


#endif