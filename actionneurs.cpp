#include "./actionnneurs.hpp"

servomotor::void enable(){
  mraa_pwm_enable(this->pwm, 1);
}

servomotor::void disable(){
  mraa_pwm_enable(this->pwm, 0);
}

servomotor::float read_pos(){
  return (int)((((mraa_pwm_read(pwm)*DEFAULT_T)-DEFAULT_PUlSE_MIN)*180/DEFAULT_PULSE_MAX)+0.5)
}

servomotor::float set_speed(float s){
  float temp = s;
  if ((temp <= 0)||(temp>=45)){
    temp = -1;
  }
  return temp;
}
servomotor::int set_pos(int s){
  actual_pos = read_pos();
  if (actual_pos!=s)
    mraa_pwm_pulsewidth_us(pwm,(int)((s*DEFAULT_PULSE_MAX/180)+0.5));
  return read_pos();
}

servomotor:: float read_speed() {
  return speed;
}
