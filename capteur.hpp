#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "type.hpp"


class capteur {
protected:
  unsigned int pin;
public:
  capteur(int x){
    pin = x;
  }
};
class photodiode: protected capteur, protected analog {
private:
  mraa_aio_context analog_in;
public :
  photodiode(unsigned int x):capteur(x),analog(){
    analog_in = mraa_aio_init(this->pin);
  }
  ~photodiode(){
    mraa_aio_close(analog_in);
  }
  virtual float get_val(){
    valeur = mraa_aio_read(analog_in); 
    return this->valeur;
  }
  unsigned int get_lux();
};
class micro: protected capteur, protected analog {
private:
  mraa_aio_context analog_in;
  float seuil_bruit;
public:
  micro(unsigned int x):capteur(x), analog(){
    analog_in = mraa_aio_init(this->pin);
    seuil_bruit = 0;
  }
  micro(unsigned int x, float y):capteur(x), analog(){
    analog_in = mraa_aio_init(this->pin);
    seuil_bruit = y;
  }
  ~micro(){
    mraa_aio_close(analog_in);
  }
  virtual float get_val(){
    this->valeur = mraa_aio_read_float(analog_in);
    return this->valeur;
  }
  float get_seuil();
  void set_seuil(float th);
};
class bouton_touch: protected capteur, protected digital{
protected:
  mraa_gpio_context gpio_in;
public:
  bouton_touch(unsigned int x):capteur(x),digital(){
    gpio_in = mraa_gpio_init(this->pin);
    mraa_gpio_dir(gpio_in, MRAA_GPIO_IN);
  }
  ~bouton_touch(){
    mraa_gpio_close(gpio_in);
  }
  virtual bool get_val(){
    valeur = (bool)mraa_gpio_read(gpio_in);
    return valeur;
  }
};

#endif
