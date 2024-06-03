// During the Diwali celebration, an electronic store is offering 5% off all
// purchases. The cost of the electrical items is Rs. 45,000 for the HP laptop, Rs.
// 2000 for the HP laptop charger, Rs. 400 for the HP headphone, Rs. 5,000 for the
// HP hard drive with 1TB of storage, and Rs. 1000 for the HP pendrive with 32GB
// of storage. Write a default C++ function to determine the total price due for the
// purchase of an electronic item.

#include <iostream>

using namespace std;

int price(int cost , float discout = 0.05){
  return cost - (cost*discout);
}

int main(){
  int cost=0,choice ;
  cout<<"what do you want to buy?"<<endl;
  while(choice != 0){
    cout<<"1. HP laptop"<<endl;
    cout<<"2. HP laptop charger"<<endl;
    cout<<"3. HP headphone"<<endl;
    cout<<"4. HP hard drive"<<endl;
    cout<<"5. HP pendrive"<<endl;
    cout<<"0. exit"<<endl;
    cin>>choice;
    if(choice == 1){
      cout<<"added HP laptop to cart"<<endl;
      cost += 45000;
    }
    else if(choice == 2){
      cout<<"added HP laptop charger to cart"<<endl;
      cost += 2000;
    }
    else if(choice == 3){
      cout<<"added HP headphone to cart"<<endl;
      cost += 400;
    }
    else if(choice == 4){
      cout<<"added HP hard drive to cart"<<endl;
      cost += 5000;
    }
    else if(choice == 5){
      cout<<"added HP pendrive to cart"<<endl;
      cost += 1000;
    }
    else if(choice == 0){
      cout<<"thank you for shopping!"<<endl;
    }
    else{
      cout<<"invalid choice"<<endl;
    }

  }

  cout<<"total cost: "<< cost <<endl;
  cout<<"total cost after discount: "<<price(cost)<<endl;
}