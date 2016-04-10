#ifndef TOURNESOL_HPP
#define TOURNESOL_HPP
#include "actionneur.hpp"
#include "capteur.hpp"
#define ANGLE_MIN 20

class tournesol {
  
private :
  unsigned int nb;
  unsigned int port_servo;
  unsigned int port_servo_cap;
  unsigned int *ports_cap;
  servomotor servo_tourne;
  servomotor servo_cap;
  photodiode * nos_cap;
  float * luminosite;
  int * position_diode;
  int pos_tourne;
public :
  tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, int les_ports[]);
  ~tournesol();
  float * get_val_cap();
  int * get_pos_cap();
  int get_pos_tourne();
  void set_pos_tourne(int pos);
  void set_pos_cap(int pos);
  int get_nb();

};
#endif
