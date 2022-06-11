/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:58:21 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 19:14:05 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
# define CONTACT_H_

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

/* cctype -> isalpha, isdigit
   iomanip -> setw,
   sstream -> used for conversion thanks to streams */
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

#endif
