#ifndef TYPE_HPP
#define TYPE_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>


class analog {
protected:
  float valeur;//peut etre une entree ou une sortie dependant de la deuxieme classe associee
public:
  virtual float get_val()=0;
};
class digital {
protected:
  bool valeur;
public:
  virtual bool get_val()=0;
};

#endif


