#include "fonction_tourne.hpp"

int find_max(int luminosite [],  int N){
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
void update_photodiode(int val[], int pos[], tournesol mysun){
  int N = (180/(mysun.get_nb()*ANGLE_MIN)) + 1;
  for (int i = 0;i<N;i++){
    float * temp1 = mysun.get_val_cap();
    int * temp2 = mysun.get_pos_cap();
    for (int j =0; j<mysun.get_nb(); j++){
      val[(i*mysun.get_nb())+j]=temp1[j];
      pos[(i*mysun.get_nb())+j]=temp2[j];
    }
  }
}
