#include "tournesol.hpp"
#include <sys/time.h>
#include <iostream>

using namespace std;

int main(){
  int ports [3] = {0,1,2};
  tournesol mysunflower(3,5,3,ports);

  int pos1 = 0;
  int pos2=0;

  while(1){
    cin>>pos1;
    cin>>pos2;
    mysunflower.set_pos_tourne(pos1);
    mysunflower.set_pos_cap(pos2);
  }
  return 0;
}
