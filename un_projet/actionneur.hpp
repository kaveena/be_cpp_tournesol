#ifndef ACTIONNEUR_HPP
#define ACTIONNEUR_HPP
#include <mraa/aio.hpp>
#include <mraa/gpio.hpp>
#include <mraa/pwm.hpp>
#include "type.hpp"
#define DEFAULT_T (20)
#define PI (3.141592653589793)
#define DEFAULT_PULSE_MIN (544)
#define DEFAULT_PULSE_MAX (2400)
#define D_PULSE (DEFAULT_PULSE_MAX-DEFAULT_PULSE_MIN)


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
  actionneurs(int x);//port associe a l'actionneur
};


/*
###############################################################################
                               LA CLASSE SERVOMOTOR
###############################################################################
*/

class servomotor : protected actionneur{

private :
  int position;
  mraa_pwm_context pwm;
public :
  //constructeurs
  servomotor():actionneur(){} 
  servomotor(unsigned int x):actionneur(x);//prend en entree le port asssocie au sermoteur
  //desctructeur
  ~servomotor();
  //active la PWM qui commande le servomoteur
  void enable();
  //disactive la PWM
  void disable();
  //Fonction qui retourne l'angle du servomoteur
  int read_pos(); 
  //Fonction qui met a jour l'angle du servomoteur
  int set_pos(int s);
};
class lcd{};

/*
###############################################################################
                               LA CLASSE LED
###############################################################################
*/
class led: protected actionneur, protected digital{
  
  protected:
  mraa_gpio_context gpio_out;
  public:
  //constructeurs
  led():actionneur(),digital(){}
  led(unsigned int x):actionneur(x),digital();
  //desctructeur
  ~led();
  void set_val(bool allume);
  void allumer();
  void eteindre();
  virtual bool get_val();
} ;

#endif

