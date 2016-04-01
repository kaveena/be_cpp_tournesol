
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "capteur.hpp"
unsigned lux[9] = {0,1,3,6,10,15,35,80,100};
unsigned int photodiode::get_lux(){
  get_val();
  int indice = (int)(valeur/100);
  indice = indice - 1;
  if (indice<0) indice = 0;
  else if (indice>8) indice = 8;
  return lux[indice];
}

float micro::get_seuil(){
  return this->seuil_bruit;
}

void micro::set_seuil(float th){
  this->seuil_bruit = th;
}
  



