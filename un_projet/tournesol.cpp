#include "tournesol.hpp"

tournesol::tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, int les_ports[]){
  //Mise a jour des ports
  this->port_servo = port_s;
  this->nb = nombre;
  this->ports_cap = new unsigned int [nb];
  for (int i = 0 ; i<nb ;i++) {
    ports_cap[i]=les_ports[i];
  }
  servo_tourne.servomotor(port_servo);
  nos_caps = new photodiode[nb];
  for(int i = 0;i<nb;i++){
    nos_caps[i]=photodiode(ports_cap[i]);
  }
  position_diode = new int [nb];
  for (int i = 0; i<nb; i++){
    position_diode[i]=ANGLE_MIN*i;
  }
  servo_cap.set_pos(0);
  lumiere = new int [nb];
  
}

int * tournesol::get_val_cap(){
  temp = new int[nb]
  for (int i = 0; i<nb<i++){
    lumiere[i]=nos_caps[i].get_val();
  }
  return temp;
}
