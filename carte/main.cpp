#include "./actionneurs.hpp"
#include "./capteur.hpp"
#include <iostream>

using namespace std;

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
  
  int seuil;
  cin>>seuil;


  while(1){          
    cout<<mic.get_val()<<" "; 
    if (mic.get_val()>seuil){
      lampe.set_val(1);
    }                     
    else {
      lampe.set_val(0);
   
    }                   
  }                            
  
  
  return 0;              
}       


