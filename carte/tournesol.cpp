#include "tournesol.hpp"

tournesol::tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, int les_ports[]){
  nb = nombre;
  ports_cap = new unsigned int [nombre];
  for (unsigned int i = 0 ; i<nb ;i++) {
    ports_cap[i]=les_ports[i];
  }
  port_servo = port_s;
  port_servo_cap = port_s2;

  servo_tourne.set_pin(port_servo);
  servo_cap.set_pin(port_servo_cap);
  
  servo_tourne.set_pos(0);
  servo_cap.set_pos(0);
  servo_tourne.enable();
  servo_cap.enable();

  nos_cap = new photodiode[nb];
  for(unsigned int i = 0;i<nb;i++){
    nos_cap[i].set_pin(ports_cap[i]);
  }
  
  luminosite = new float[nb];
  get_val_cap();
  
  position_diode = new int [nb];
  get_pos_cap();

  get_pos_tourne();
}

tournesol::~tournesol(){
  delete[] ports_cap;
  delete[] nos_cap;
  delete[] luminosite;
  delete[] position_diode;
}

float * tournesol::get_val_cap(){
  float * temp = new float[nb];
  for (unsigned int i = 0; i<nb ; i++){
    luminosite[i]=nos_cap[i].get_val();
    temp[i]=luminosite[i];
  }
  return temp;
}

int * tournesol::get_pos_cap(){
  int * temp = new int[nb];
  for (unsigned int i = 0; i<nb ; i++){
    position_diode[i]=(i*ANGLE_MIN)+servo_cap.read_pos();
    temp[i]=position_diode[i];
  }
  return temp;
}

int tournesol::get_pos_tourne(){
  return servo_tourne.read_pos();
}

void tournesol::set_pos_tourne(int pos){
  servo_tourne.set_pos(pos);
}

void tournesol::set_pos_cap(int pos){
  servo_cap.set_pos(pos);
}

int tournesol::get_nb(){
  return this->nb;
}

