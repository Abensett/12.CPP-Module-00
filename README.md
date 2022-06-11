# 12.-C++ MODULE 00
First project of C++ piscine

# SUMMARY : 

  * Namespaces  
  * Classes  
  * Fonctions membres
  * Stdiostreams  
  * Listes d’initialisation
  * Static, Const
  * autre bases
 
  ### Namespaces


<details>
<summary> It's a local scope </summary>
 
> * Namespaces provide a method for preventing name conflicts in large projects.
>
> * Symbols declared inside a namespace block are placed in a named scope that prevents them from being mistaken for identically-named symbols in other scopes.
</details>



### STDIOSTREAMS
<details>
<summary>std::cout << "HELLO WORLD !" << std::endl </summary>

 

      std::cout <<
      std::cin >> buff
      std::cout << "You entered" <<buff<< std::endl 
      std::endl = passage à la ligne
      using std::cout;  => pour juste ecrire cout*
</details>

### CLASSES

[voir Phonebook.hpp](./ex01/PhoneBook.hpp)

### CONST

<details> 
<summary> [voir Contact.hpp](./ex01/Contact.hpp) </summary>

      
      const char c1;           //Le caractère ne peut être modifié
      const char * c2;         //Le caractère pointé ne peut être modifié
      char * const c3;         //Le pointeur vers le caractère ne peut être modifié
      const char * const c4;   //Le pointeur ET le caractère pointé ne peuvent être modifiés
      Dans le cas d'une fonction membre un const en fin de fonction 
      signifie qu'elle ne modifie pas l'instance de classe 
 
</details>


 
