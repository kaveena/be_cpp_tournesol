#include "./actionneurs.hpp"
#include "./capteur.hpp"

int find_max(int donnee[], int l){
  int max = 0;
  int imax = 0;
  for (int i = 0; i<l, i++){
    if(donnee[i]>max){
      max=donnee[i];
      imax = i;
  }
    return imax;
}

  void mise_a_jour(){
    
  }

int main(){
  servomotor un_servo(3);
  un_servo.enable();
  servomotor deux_servo(2);
  deux_servo.enable();                  
  bouton_touch touch(5);
  micro mic(2);         
  photodiode lumiere(0);
  led lampe(8);              
  photodiode lumiere_deux(1);
  photodiode lumiere_trois(2);
  photodiode lumiere_quatre(3);
  int les_lumiers[4];           

  while(1){          
    msleep(20);
    void mise_a_jour();
    if (mic.get_val()>300){ 
      lampe.set_val(1);
    }                     
    else {
      lampe.set_val(0);
   
    }                   
  }                            
  
  
  return 0;              
}       

