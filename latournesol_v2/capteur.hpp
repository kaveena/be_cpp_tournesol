#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "type.hpp"


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
  //contructeurs
  photodiode();
  photodiode(unsigned int x);
  //destructeur
  ~photodiode();
  //Fonction qui renvoie la luminosite du capteur
  unsigned int get_lux();
  //voir classes meres
  virtual void set_pin(unsigned int x);
  virtual float get_val();
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
  //constructeurs
  micro();
  micro(unsigned int x);
  //entree: pin , seuil de bruit
  micro(unsigned int x, float y);
 //destructeur
  ~micro();  
  //getters
  float get_seuil();
  //setters
  void set_seuil(float th);
  //Voir classes meres
  virtual void set_pin(unsigned int x);
  virtual float get_val();
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
  //constructeurs
  bouton();
  bouton(unsigned int x);
  //destructeur
  ~bouton();
  //Voir classes meres
  virtual void set_pin(unsigned int x);
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
  //constructeurs
  potentiometer();
  potentiometer(unsigned int x);
  //destructeur
  ~potentiometer();
  //Voir classes meres
  virtual void set_pin(unsigned int x);
  virtual float get_val();
};

#endif

