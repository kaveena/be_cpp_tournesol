#include "type.hpp"

/*
###############################################################################
                               LA CLASSE CAPTEUR
###############################################################################
*/

capteur::capteur(unsigned int x){
  pin = x;
}

unsigned int capteur::get_pin(){
  return this->pin;
}

/*
###############################################################################
                               LA CLASSE ACTIONNEUR
###############################################################################
*/
actionneur::actionneur(unsigned int x){
  this->pin = x;
}

unsigned int actionneur::get_pin(){
  return this->pin;
}
