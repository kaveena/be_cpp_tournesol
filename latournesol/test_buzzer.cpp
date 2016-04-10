#include "actionneur.hpp"

int main(){
  servomotor myservo(6);
  buzzer mybuzz(3);
  
  myservo.set_pos(90);
  myservo.enable();
  sleep(1);
  mybuzz.set_mel(0);
  myservo.set_pos(45);
  sleep(1);
  myservo.set_pos(0);
  mybuzz.set_mel(1);
  sleep(1);
  mybuzz.stop();
  return 0;
}
