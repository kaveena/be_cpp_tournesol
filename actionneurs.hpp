#ifndef ACTIONNEURS_HPP
#define ACTIONNEURS_HPP
#include <mraa/aio.hpp>
#include <mraa/gpio.hpp>
#include <mraa/pwm.hpp>

#define DEFAULT_T (20)
#define PI (3.141592653589793)
#define DEFAULT_PULSE_MIN (544)
#define DEFAULT_PULSE_MAX (2400)
#define D_PULSE (DEFAULT_PULSE_MAX-DEFAULT_PULSE_MIN)

class actionneurs {
protected:
  int pin;
public:
  actionneurs(int x){
    pin=x;
  }

};

class servomotor : protected actionneurs{

private :
  int position;
  int speed;
  mraa_pwm_context pwm;
public :
  servomotor(int x):actionneurs(x){
    pwm = mraa_pwm_init(x);
    mraa_pwm_period_ms(pwm,DEFAULT_T);
  }
  ~servomotor(){
    mraa_pwm_close(pwm);
  }
  void enable();	
  
  void disable();
  
  float read_pos();
  
  /*	Function which sets the angular position of the servo
	IN : angle of the servo in degrees
	OUT : actual angle 
  */
  float set_pos(float s);
	
  /*	Function which sets the angular speed of the servo when the
	function set_pos is used
	IN : desired angular speed
	OUT : actual angular speed
  */
	
  float set_speed(float s);
	
  float read_speed();
	
};
class lcd{};

#endif
