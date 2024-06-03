#include <iostream>

using namespace std;

int main(){
  int hours;
  cout<<"Enter hours: ";
  cin>>hours;
  int a,b,c;
  a = hours*500;
  if (hours>6){
    b = ((hours-6)*100) + 1000;
  }
  else{
    b = 1000;
  }
  if (hours>12){
    c = (hours-12)*200 + 1500;
  }
  else{
    c = 1500;
  }


  if (a<=b && a<=c){
    cout<<"a is the best option for you at "<< a << "$" << endl;
  }
  else if (b<=a && b<=c){
    cout<<"b is the best option for you at "<< b << "$" << endl;
  }
  else{
    cout<<"c is the best option for you at "<< c << "$" << endl;
  }



}

