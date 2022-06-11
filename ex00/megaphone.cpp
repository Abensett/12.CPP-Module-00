/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/11 18:53:55 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*	This file defines les objets cin, cout, cerr et clog,
 respectivement  flux d'entrée standard,
flux de sortie standard,
flux d'erreur standard non mis en mémoire tampon et
flux d'erreur standard mis en mémoire tampon.*/
#include <cstring>

/* This file defines many string functions such as strlen*/

/*  - std est le namespace
    - << operateur d'insertion
    - endl  = \n */

using std::cout;

int main(int ac, char **av)
{

    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    while (--ac)
    {
        av++;
        for (unsigned int i = 0; i < strlen(*av); i++)
            (*av)[i] = std::toupper((*av)[i]);
        cout << *av;
    }
    cout << std::endl;
    return(0);
}
