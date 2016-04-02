#ifndef FONCTION_TOURNE_HPP
#define FONCTION_TOURNE_HPP
#include "tournesol.hpp"
#include <iostream>

int find_max(int luminosite[],int N);
/* Fonction qui retourne l'index du tableau
   qui contient la valeur max
   N est la longueur du tableau */

void update_photodiode(float val[], int pos[], tournesol mysun);
/* Fonction qui fait une acquisition des
   photodiodes
   port contient les numero de ports des photodiodes
   N est le nombre de photodiode
*/

#endif


