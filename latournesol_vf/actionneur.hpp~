#ifndef ACTIONNEUR_HPP
#define ACTIONNEUR_HPP
#include <mraa/aio.hpp>
#include <mraa/gpio.hpp>
#include <mraa/pwm.hpp>
#include "type.hpp"

#define PI (3.141592653589793)

#define DEFAULT_T (20)
#define DEFAULT_PULSE_MIN (544)
#define DEFAULT_PULSE_MAX (2400)
#define D_PULSE (DEFAULT_PULSE_MAX-DEFAULT_PULSE_MIN)
#define DEFAULT_ANGLE_MIN 0
#define DEFAULT_ANGLE_MAX 180
#define D_ANGLE (DEFAULT_ANGLE_MAX-DEFAULT_ANGLE_MIN)


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
  actionneur(unsigned int x);//port associe a l'actionneur
  virtual void set_pin(unsigned int x) = 0;
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
  servomotor();
  servomotor(unsigned int x);//prend en entree le port asssocie au sermoteur
  //desctructeur
  ~servomotor();
  virtual void set_pin(unsigned int x);
  //active la PWM qui commande le servomoteur
  void enable();
  //disactive la PWM
  void disable();
  //Fonction qui retourne l'angle du servomoteur
  int read_pos(); 
  //Fonction qui met a jour l'angle du servomoteur
  int set_pos(int s);
};

/*
###############################################################################
                               LA CLASSE BUZZER
###############################################################################
*/

class buzzer : protected actionneur{

private :
  mraa_pwm_context pwm;
  int mel;
  float volume;
  static float notes[7]; //contient les periodes associees au differentes notes

public :
  //constructeurs
  buzzer();
  buzzer(unsigned int x);//prend en entree le port asssocie au buzzer
  //desctructeur
  ~buzzer();
  virtual void set_pin(unsigned int x);
  //active la PWM qui commande le buzzer
  void enable();
  //disactive la PWM
  void disable();
  //Fonction qui emet la note correspondante
  void set_mel(unsigned int m);
  //Fonction qui renvoie la note actuellement implementee
  int read_mel();
  //Fonction qui regle le volume du son vol est entre 0 et 1
  void set_vol(float vol);
  //Fonction qui renvoie la valeur actuelle du son
  float get_vol();
  //Arrete le son
  void stop();
};

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
  led();
  led(unsigned int x);
  //desctructeur
  ~led();
  virtual void set_pin(unsigned int x);
  void set_val(bool allume);
  void allumer();
  void eteindre();
  virtual bool get_val();
} ;

#endif

