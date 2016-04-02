#ifndef TOURNESOL_HPP
#define TOURNESOL_HPP
#include "actionneurs.hpp"
#include "capteur.hpp"
#define ANGLE_MIN 20

class tournesol {
  
private :
  unsigned int nb;//Le nombre de capteurs de lumiere utilises
  unsigned int *ports_cap; //un tableau de contenant les numeros de ports des capteur de gauche vers la droite
  unsigned int port_servo; //le port du servo qui tourne le tournesol
  servomotor servo_tourne; //le servomoteur du tournesol
  servomotor servo_cap; //le servomoteur des capteurs
  photodiode * nos_caps; //un tableau de photodiodes
  int * position_diode; //retourne les angles des capteurs
  int pos_tourne; //l'angle du tournesol
  float * lumiere; //les luminosites
public :
  //constructeur
  tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, unsigned int *les_ports);
  //Fonction qui retourne l'angle du tournesol
  int get_pos_tournesol();

  //Fonction qui retourne les angles des capteurs 
  //indice 0 -> capteur0
  int * get_pos_cap();

  //Fonction qui retourne les valeurs des capteurs
  //indice 0 -> capteur0
  int * get_val_cap();

  //Fonction qui fait tourner le tournesol a l'angle "pos"
  void set_pos_tournesol(int pos);

  //Fonction qui fait tourner le capteur0 a "pos"
  void set_pos_cap(int pos);
  
};
