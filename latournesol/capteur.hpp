#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "type.hpp"
/*
###############################################################################
                               LA CLASSE CAPTEUR
###############################################################################
*/

class capteur {
protected:
  unsigned int pin;
public:
  capteur(){}
  capteur(unsigned int x);
  virtual void set_pin(unsigned int x) = 0;
};

/*
###############################################################################
                               LA CLASSE PHOTODIODE
###############################################################################
*/
class photodiode: protected capteur, protected analog {
private:
  mraa_aio_context analog_in;
  static unsigned int lux[9];
public :
  photodiode();
  photodiode(unsigned int x);
  ~photodiode();
  virtual void set_pin(unsigned int x);
  virtual float get_val();
  unsigned int get_lux();
};

/*
###############################################################################
                               LA CLASSE MICRO
###############################################################################
*/

class micro: protected capteur, protected analog {
private:
  mraa_aio_context analog_in;
  float seuil_bruit;
public:
  micro();
  micro(unsigned int x);
  micro(unsigned int x, float y);
  ~micro();
  virtual void set_pin(unsigned int x);
  virtual float get_val();
  float get_seuil();
  void set_seuil(float th);
};

/*
###############################################################################
                               LA CLASSE BOUTON TOUCH
###############################################################################
*/

class bouton: protected capteur, protected digital{
protected:
  mraa_gpio_context gpio_in;
public:
  bouton();
  bouton(unsigned int x);
  ~bouton();
  void set_pin(unsigned int x);
  virtual bool get_val();
};

/*
###############################################################################
                               LA CLASSE POTENTIOMETRE
###############################################################################
*/

class potentiometer: protected capteur, protected analog{
protected:
  mraa_aio_context analog_in;
public :
  potentiometer();
  potentiometer(unsigned int x);
  ~potentiometer();
  virtual void set_pin(unsigned int x);
  virtual float get_val();
};

#endif

