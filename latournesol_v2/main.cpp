#include "fonction_tourne.hpp"
#include <iostream>
#include "ecran.hpp"

using namespace std;

int main(){
  int ports [3] = {1,2,3}; //Ports des photodiodes
  bouton myswitch(2);//switch pour changer de mode
  bouton ON(7);
  bool bouton_avant=false;
  bool bouton=myswitch.get_val();
  bool OFF;
  bool ON_avant;
  
  potentiometer mypot(0);//potentiometre pour le mode manuel
  unsigned int mode = 0; //On commence par le mode 0
  lcd myscreen;
  int val_pot;
  string str_val_pot;
  unsigned int mode_avant=1;
  int val_pot_avant=0;

  //Demarrage
  myscreen.change_cou(255,50,255);
  myscreen.print_msg("WELCOME","Touch to start");
  while (ON.get_val()==false){usleep(100000);}//attend tant qu'on n'appuie pas sur le bouton de demarrage
  OFF = false;
  ON_avant = true;
  tournesol mysunflower(3,5,3,ports);
  while(!(OFF)){
    //--------------------------------------------------------------------------
    //detection d'un appuie sur le bouton MODE
    if ((!bouton_avant)&&(bouton)){
      //On change de mode sur front montant
      if (mode == 0){
	mode = 1;
      }
      else{
	mode = 0;
      }
    }
    //---------------------------------------------------------------------------
    //Detection d'un appuie du bouton ON/OFF
    if ((!ON_avant)&&ON.get_val()){
      OFF = true;
    }
    if (!(OFF)){
      //--------------------------------------------------------------------------
      // MODE MANUEL
      if (mode ==0){
	//Mode Manuel
	//On commande la tournesol avec le potentiometre
	str_val_pot = mode_manuel(mypot,mysunflower,val_pot,val_pot_avant);
	if (mode_avant!=mode){
	  myscreen.change_cou(0,0,255);
	}
	if ((mode_avant!=mode)||(val_pot_avant!=val_pot)){
	  str_val_pot = "Angle :" + str_val_pot;
	  myscreen.print_msg("Mode : Manual",str_val_pot);
	}
	mode_avant=0;
      }
      // MODE AUTOMATIQUE
      else if (mode == 1){
	if (mode_avant!=mode){
	  //On fait une calibration quand on entre dans le mode automatique
	  myscreen.print_msg("Mode : Auto","Calibrating...");
	  myscreen.change_cou(255,255,0);
	  mode_auto_calibrate(mysunflower);
	  myscreen.print_msg("Mode : Auto","Tracking");
	} 
	mode_avant=1;
	mode_auto_track(mysunflower);
      }
      //mise a jour des valeurs du bouton MODE
      bouton_avant = bouton;
      usleep(5000);
      bouton = myswitch.get_val();
    }

    //mise a jour des valeurs du bouton ON/OFF
    ON_avant = ON.get_val();
    usleep(20000);
  }
  //Efface l'ecran et eteint la lumiere de fond
  myscreen.clear_screen();
  myscreen.change_cou(0,0,0);
  return 0;
}
