/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:54:28 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 21:42:31 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include "Contact.hpp"


/* 3 types of constructors : defaut, d' initialisation (with parameters) and by copy*/
class PhoneBook {
public :
    PhoneBook(void);                             // constructeur par defaut
    ~PhoneBook(void);                            // destructeur = procedures sans type de retour
                                                 // 2 fonctions membres
    void Add(void);                              // Not const because it modifies phonebook  = WRITE
    void SearchContact(void) const;              // const car ne modifie pas                 = READONLY

private:
    int        _number;
    Contact    _contacts[8];                      //_variable_privé

};


#endif
