/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 23:04:44 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*	This file defines les objets cin, cout, cerr et clog,
 respectivement  flux d'entrée standard,
flux de sortie standard,
flux d'erreur standard non mis en mémoire tampon et
flux d'erreur standard mis en mémoire tampon.*/
#include <string>

/* This file defines many string functions such as strlen*/

/*  - std est le namespace standard
    - << operateur d'insertion
    - :: Operateur de resolution de portee permet de recuperer les infos du namespace
    - endl  = \n */

using std::cout;
using std::string;

int main(int ac, char **av)
{
    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (int j = 1; j < ac; j++)
    {
        string str(av[j]);
        for (unsigned int i = 0; i < str.length(); i++)
            cout << (char)std::toupper(str[i]);
    }
    cout << std::endl;
    return(0);
}
