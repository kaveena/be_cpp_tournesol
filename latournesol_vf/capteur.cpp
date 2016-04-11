#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "capteur.hpp"
unsigned int photodiode::lux[9] = {0,1,3,6,10,15,35,80,100};

/*
###############################################################################
                               LA CLASSE PHOTODIODE
###############################################################################
*/

photodiode::photodiode():capteur(),analog(){
  analog_in = NULL; 
} 
photodiode::photodiode(unsigned int x):capteur(x),analog(){
  analog_in = mraa_aio_init(this->pin);
}
photodiode::~photodiode(){
  if (analog_in!=NULL)
    mraa_aio_close(analog_in);
}

void photodiode::set_pin(unsigned int x){
  this->pin = x;
  analog_in = mraa_aio_init(this->pin);
}

float photodiode::get_val(){
  valeur = mraa_aio_read(analog_in); 
  return this->valeur;
}
unsigned int photodiode::get_lux(){
  get_val();
  int indice = (int)(valeur/100);
  indice = indice - 1;
  if (indice<0) indice = 0;
  else if (indice>8) indice = 8;
  return lux[indice];
}

/*
###############################################################################
                               LA CLASSE MICRO
###############################################################################
*/
micro::micro():capteur(),analog(){
  analog_in = NULL;
}
micro::micro(unsigned int x):capteur(x), analog(){
  analog_in = mraa_aio_init(this->pin);
  seuil_bruit =0;
}
micro::micro(unsigned int x, float y):capteur(x), analog(){
  analog_in = mraa_aio_init(this->pin);
  seuil_bruit = y;
}
micro:: ~micro(){
  if (analog_in != NULL)
    mraa_aio_close(analog_in);
}

void micro::set_pin(unsigned int x){
  this->pin = x;
  analog_in = mraa_aio_init(this->pin);
  seuil_bruit =0;
}

float micro::get_val(){
    this->valeur = mraa_aio_read(analog_in);
    return this->valeur;
}
float micro::get_seuil(){
  return this->seuil_bruit;
}

void micro::set_seuil(float th){
  this->seuil_bruit = th;
}
  
/*
###############################################################################
                               LA CLASSE BOUTON
###############################################################################
*/

bouton::bouton():capteur(),digital(){
  gpio_in=NULL;
}

bouton::bouton(unsigned int x):capteur(x),digital(){
  gpio_in = mraa_gpio_init(this->pin);
  mraa_gpio_dir(gpio_in, MRAA_GPIO_IN);
}
bouton:: ~bouton(){
  if (gpio_in!=NULL)
    mraa_gpio_close(gpio_in);
}

void bouton::set_pin(unsigned int x){
  this->pin = x;
  gpio_in = mraa_gpio_init(this->pin);
  mraa_gpio_dir(gpio_in, MRAA_GPIO_IN);
}
bool bouton::get_val(){
  valeur = (bool)mraa_gpio_read(gpio_in);
  return valeur;
}


/*
###############################################################################
                               LA CLASSE POTENTIONMETER
###############################################################################
*/

potentiometer::potentiometer():capteur(),analog(){
  analog_in = NULL; 
} 
potentiometer::potentiometer(unsigned int x):capteur(x),analog(){
  analog_in = mraa_aio_init(this->pin);
}
potentiometer::~potentiometer(){
  if (analog_in!=NULL)
    mraa_aio_close(analog_in);
}

void potentiometer::set_pin(unsigned int x){
  this->pin = x;
  analog_in = mraa_aio_init(this->pin);
}

float potentiometer::get_val(){
  valeur = mraa_aio_read(analog_in); 
  return this->valeur;
}
