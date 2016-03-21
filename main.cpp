#include "./actionneurs.hpp"

int main(){
  servomotor un_servo(3);
  un_servo.enable();

  servomotor deux_servo(5);
  deux_servo.enable();

  un_servo.set_pos(0);
  deux_servo.set_pos(0);
  sleep(2);
  un_servo.set_pos(180);deux_servo.set_pos(180);
  sleep(2);
  un_servo.set_pos(90);deux_servo.set_pos(90);
  sleep(2);

  return 0;
}
