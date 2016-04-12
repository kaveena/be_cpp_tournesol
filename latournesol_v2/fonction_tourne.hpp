#ifndef FONCTION_TOURNE_HPP
#define FONCTION_TOURNE_HPP
#include "tournesol.hpp"
#include <iostream>
#include <sstream>
#include <string>

/* Fonction qui retourne l'index du tableau
   qui contient la valeur max
   N est la longueur du tableau */
int find_max(float luminosite[],int N);

/* Fonction qui fait une acquisition des
   photodiodes
   port contient les numero de ports des photodiodes
   N est le nombre de photodiode
*/
void update_photodiode(float val[], int pos[], tournesol & mysun);

/*
Fonction qui tri les valeurs d'angle supérieur a 180 et les remplace par un -1 
 */
void tri(float val[], int pos[], int N);

/*
  Fonction qui fait suivre la lumiere au degre pres
*/
int suivre_lum(tournesol & mysunflower);

/* 
   Entree: le potentiometre, le tournesol, la valeur du potentiometre qui va etre modifier, la valeur precedente du potentiometre
   Sortie: String contenant l'angle la consigne venant du potentiometre"
*/
std::string mode_manuel(potentiometer & pot,tournesol & mysunflower,int & val_pot,int val_pot_avant);

/*
  Phase de calibration du mode automatique
  les capteurs font 180 deg en pas de ANGLE_MIN (l'angle entre les capteurs qui est de 20 deg)
  Et se positionne de facon a avoir le capteur du milieu au point d'intensite luminueus max
  Et positionne le tournesol sur le point d'intensite max
 */
void mode_auto_calibrate(tournesol & mysunflower);

/*
  Le tournesol et le capteur du milieu cherche a suivre la lumiere qui bouge "assez lentement" en comparant les valeurs des capteurs
 */
int mode_auto_track(tournesol & mysunflower);


#endif


