#include "ecran.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main(){

  lcd monecran;
  string un_msg;
  int r;
  int g;
  int b;
  
  int a = 10;
  stringstream ss;
  ss << a;
  string str = ss.str();
  while(1){
    cin>>un_msg;
    un_msg = un_msg + str;
    //cin>>r; //cin>>g; //cin>>b; //monecran.change_cou(r,g,b);
    monecran.print_msg(un_msg, str);
  }

  return 0;
}
