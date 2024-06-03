// A police camp is recruiting the trainees by measuring the parameters such as
// height, age, and chest. The minimum eligibility for selection is based on the
// following conditions:
//  Height should be between 5.2 to 5.6 inches
//  Age should be greater than 18 and less than 25
//  Chest should be greater than 45 cm
// Write an inline function to find whether the person is fit for the police or not.
// Print “Selected“ when criteria is satisfied and print “Not selected” when
// criteria are not satisfied.

#include <iostream>

using namespace std;

inline bool isFit(float height, int age, int chest){return (height>=5.2 && height<=5.6 && age>18 && age<25 && chest>45);}


int main(){
  float height;
  int age, chest;
  cout<<"Enter height: ";
  cin>>height;
  cout<<"Enter age: ";
  cin>>age;
  cout<<"Enter chest: ";
  cin>>chest;
  if (isFit(height, age, chest)){
    cout<<"Selected"<<endl;
  }
  else{
    cout<<"Not selected"<<endl;
  }
}
