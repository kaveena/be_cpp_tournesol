#ifndef TOURNESOL_HPP
#define TOURNESOL_HPP
#include "actionneur.hpp"
#include "capteur.hpp"
#define ANGLE_MIN 20

//ANGLE_MIN est l'angle que nous avons entre nos photodiodes qui est de
//20 deg sur notre prototype

class tournesol {
  
private :
  unsigned int nb; //nombre de photodiodes
  unsigned int port_servo; //port du servo qui controle le tournesol
  unsigned int port_servo_cap; //port du servo qui controle les capteurs
  unsigned int *ports_cap; //ports des photodiodes
  servomotor servo_tourne; //servo qui controle le tournesol
  servomotor servo_cap; //servo qui controle les capteurs
  photodiode * nos_cap; //les photodiodes
  float * luminosite; //les valeurs des photodiodes
  int * position_diode; //les positions des photodiodes
  int pos_tourne; //la position du tournesol
public :
  //constructeur
  //Entree : port du servo qui controle le tournesol
  //         port du servo qui controle les capteurs
  //         nombre de photodiodes
  //         les ports des photodiodes
  tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, int les_ports[]);
  //destructeur
  ~tournesol();
  //getters
  int get_nb();
  float * get_val_cap();
  int * get_pos_cap();
  int get_pos_tourne();
  //setters
  void set_pos_tourne(int pos);
  void set_pos_cap(int pos);
  

};
#endif
