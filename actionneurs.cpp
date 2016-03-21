#include "./actionneurs.hpp"

void servomotor::enable(){
  mraa_pwm_enable(this->pwm, 1);
}

void servomotor::disable(){
  mraa_pwm_enable(this->pwm, 0);
}

float servomotor::read_pos(){
  float temp =mraa_pwm_read(pwm)*DEFAULT_T*1000;
  temp =((180*temp)/(D_PULSE))-(180*DEFAULT_PULSE_MIN/(D_PULSE));
  return (int)(temp+0.5);
}

float servomotor::set_speed(float s){
  float temp = s;
  if ((temp <= 0)||(temp>=45)){
    temp = -1;
  }
  return temp;
}
float servomotor::set_pos(float s){
  float actual_pos = read_pos();
  if (actual_pos!=s)
    mraa_pwm_pulsewidth_us(pwm,(int)(((s*D_PULSE/180)+DEFAULT_PULSE_MIN)+0.5));
  return read_pos();
}

float servomotor::read_speed() {
  return speed;
}
