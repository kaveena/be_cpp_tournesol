#ifndef FONCTION_TOURNE_HPP
#define FONCTION_TOURNE_HPP
#include "tournesol.hpp"
#include <iostream>
#include <sstream>
#include <string>

int find_max(float luminosite[],int N);
/* Fonction qui retourne l'index du tableau
   qui contient la valeur max
   N est la longueur du tableau */

void update_photodiode(float val[], int pos[], tournesol & mysun);
/* Fonction qui fait une acquisition des
   photodiodes
   port contient les numero de ports des photodiodes
   N est le nombre de photodiode
*/
void tri(float val[], int pos[], int N);
/*
Fonction qui tri les valeurs d'angle supérieur a 180 
 */
int suivre_lum(tournesol & mysunflower);
/*
  Fonction qui fait suivre la lumiere au degre pres
*/


std::string mode_manuel(potentiometer & pot,tournesol & mysunflower,int & val_pot,int val_pot_avant);
void mode_auto_calibrate(tournesol & mysunflower);
int mode_auto_track(tournesol & mysunflower);


#endif


