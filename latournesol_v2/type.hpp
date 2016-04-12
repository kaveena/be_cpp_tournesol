#ifndef TYPE_HPP
#define TYPE_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>

/*
###############################################################################
                               LA CLASSE ANALOG
###############################################################################
*/

class analog {
protected:
  float valeur;//peut etre une entree ou une sortie dependant de la deuxieme classe associee
public:
  virtual float get_val()=0; // sortie : valeur du capteur
};

/*
###############################################################################
                               LA CLASSE DIGITAL
###############################################################################
*/

class digital {
protected:
  bool valeur; //peut etre une entree ou une sortie dependant de la deuxieme classe associee
public:
  virtual bool get_val()=0; // sortie : valeur du capteur
};

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
  capteur(unsigned int x);//entree : port associe au capteur
  unsigned int get_pin();
  virtual void set_pin(unsigned int x) = 0;
};

/*
###############################################################################
                               LA CLASSE ACTIONNEUR
###############################################################################
*/

class actionneur {
protected:
  unsigned int pin;
public:
  //contructeurs
  actionneur(){}
  actionneur(unsigned int x);//entree : port associe a l'actionneur
  unsigned int get_pin();;//sortie : port associe a l'actionneur
  virtual void set_pin(unsigned int x) = 0;;//entree : port associe a l'actionneur
};

#endif



