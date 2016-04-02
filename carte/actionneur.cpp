#include "./actionneur.hpp"

actionneur::actionneur(unsigned int x){
  this->pin = x;
}


/*
###############################################################################
                               LA CLASSE SERVOMOTOR
###############################################################################
*/

servomotor::servomotor():actionneur(){
  pwm = NULL;
}

servomotor::servomotor(unsigned int x):actionneur(x){
  pwm = mraa_pwm_init(x);
  mraa_pwm_period_ms(pwm,DEFAULT_T);
}

servomotor::~servomotor(){
  mraa_pwm_close(pwm);
}

void servomotor::set_pin(unsigned int x){
  this->pin = x;
  pwm = mraa_pwm_init(x);
  mraa_pwm_period_ms(pwm,DEFAULT_T);
}

void servomotor::enable(){
  mraa_pwm_enable(this->pwm, 1);
}

void servomotor::disable(){
  mraa_pwm_enable(this->pwm, 0);
}

int servomotor::read_pos(){
  float temp =mraa_pwm_read(pwm)*DEFAULT_T*1000;
  temp =((180*temp)/(D_PULSE))-(180*DEFAULT_PULSE_MIN/(D_PULSE));
  return (int)(temp+0.5);
}

int servomotor::set_pos(int s){
  int actual_pos = read_pos();
  if (actual_pos!=s)
    mraa_pwm_pulsewidth_us(pwm,(int)(((s*D_PULSE/180)+DEFAULT_PULSE_MIN)+0.5));
  return read_pos();
}


/*
###############################################################################
                               LA CLASSE LED
###############################################################################
*/

led::led():actionneur(),digital(){
  gpio_out = NULL;
}

led::led(unsigned int x): actionneur(x),digital(){
  gpio_out = mraa_gpio_init(this->pin);
  mraa_gpio_dir(gpio_out, MRAA_GPIO_OUT);
}

led::~led(){
  mraa_gpio_close(gpio_out);
}

void led::set_pin(unsigned int x){
  this->pin = x;
  gpio_out = mraa_gpio_init(this->pin);
  mraa_gpio_dir(gpio_out, MRAA_GPIO_OUT);
}

void led ::set_val(bool allume) {
  this->valeur = allume;
  mraa_gpio_write (gpio_out, allume);
}

void led::allumer(){
  set_val(true);
}

void led::eteindre(){
  set_val(false);
}

bool led::get_val(){
  return this->valeur;
}


