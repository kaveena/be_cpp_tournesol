#include "fonction_tourne.hpp"

using namespace std;

int find_max(float luminosite [],  int N){
  int max = 0;
  int imax = 0;
  for (int i = 0; i<N; i++){
    if(luminosite[i]>max){
      max = luminosite[i];
      imax = i;
    }
  }
  return imax;
}
void update_photodiode(float val[], int pos[], tournesol & mysun){
  int N = (180/(mysun.get_nb()*ANGLE_MIN)) + 1;
  for (int i = 0;i<N;i++){
    sleep(1);
    mysun.set_pos_cap(i*mysun.get_nb()*ANGLE_MIN);
    float * temp1 = mysun.get_val_cap();
    int * temp2 = mysun.get_pos_cap();
    for (int j =0; j<mysun.get_nb(); j++){
      val[(i*mysun.get_nb())+j]=temp1[j];
      pos[(i*mysun.get_nb())+j]=temp2[j];
    }
    delete temp1;
    delete temp2;
  }
}

void tri(float val[], int pos[], int N){
  for (int i = 0;i<N;i++){
    if (pos[i]>181){
      pos[i]=0;
      val[i]=-1;
    }
  }
}

int suivre_lum(tournesol & mysunflower){
  float *val;
  int *pos;
  int sortie;
  val = mysunflower.get_val_cap();
  pos = mysunflower.get_pos_cap();
  cout<<val[0]<<" "<<val[1]<<" "<<val[2]<<endl;
  int i = find_max(val,mysunflower.get_nb());
  switch(i){
  case 0:
    sortie = pos[0]-1;
    break;
  case 1:
    sortie = pos[0];
    break;
  case 2:
    sortie = pos[0]+1;
    break;
  }
  delete val;
  delete pos;
  if (sortie<0){
    sortie = 0;
  }
  else if (sortie>180 - (2*ANGLE_MIN)){
    sortie = 180 - (2*ANGLE_MIN);
  }
  mysunflower.set_pos_cap(sortie);
  return (sortie+ANGLE_MIN);
}

string mode_manuel(potentiometer & pot,tournesol & mysunflower,int & val_pot,int val_pot_avant){
      //Mode Manuel
      //On commande la tournesol avec le potentiometre
  stringstream ss_val_pot;
  string str_val_pot;
  val_pot=int((pot.get_val()/1023)*180.0+0.5);
  mysunflower.set_pos_tourne(val_pot);
  ss_val_pot << val_pot;
  str_val_pot = ss_val_pot.str();  
  val_pot_avant = val_pot;
  ss_val_pot.str("");
  ss_val_pot.clear();
  return str_val_pot;
}

void mode_auto_calibrate(tournesol & mysunflower){
  int nombre_de_val = ((180/(3*ANGLE_MIN)) + 1)*3;
  float valeurs[nombre_de_val];
  int position_cap[nombre_de_val];
  int le_max;
  update_photodiode(valeurs,position_cap,mysunflower);
  tri(valeurs,position_cap,nombre_de_val);
  le_max = find_max(valeurs,nombre_de_val);
  mysunflower.set_pos_cap(position_cap[le_max]-ANGLE_MIN);
  mysunflower.set_pos_tourne(160-position_cap[le_max]);
}

int mode_auto_track(tournesol & mysunflower){
  int poursuite = suivre_lum(mysunflower);
  mysunflower.set_pos_tourne(160-poursuite);
  return poursuite;
}
