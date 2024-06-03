// Construct a C++ program that converts an amount of money from one currency
// to another. The program should allow the user to input the amount in one
// currency and select the target currency for conversion. You will need to provide
// the exchange rates for the conversion.
// Test Case:
// Suppose the user wants to convert $100 USD to Euros (EUR).
// Input:
// - Amount in USD: 100
// - Choice: 1 (for Euro)
// Expected Output:
// - The program should output the converted amount in Euros (EUR) based on
// the exchange rate.
// Calculation:
// - Given exchange rate: 1 USD = 0.85 EUR
// - Converted amount = 100 USD * 0.85 EUR/USD = 85 EUR
// *Expected Output:*
// Currency Converter
// ------------------
// Enter amount in USD: 100
// Choose target currency:
// 1. Euro (EUR)
// 2. British Pound (GBP)
// 3. Japanese Yen (JPY)
// Enter your choice (1, 2, or 3): 1
// Converted amount: 85.00 EUR

#include <iostream>

using namespace std;

int main(){
  float amount;
  int choice;
  cout<<"Enter amount in USD: ";
  cin>>amount;
  cout<<"Choose target currency:"<<endl;
  cout<<"1. Euro (EUR)"<<endl;
  cout<<"2. British Pound (GBP)"<<endl;
  cout<<"3. Japanese Yen (JPY)"<<endl;
  cout<<"Enter your choice (1, 2, or 3): ";
  cin>>choice;
  if (choice==1){
    cout<<"Converted amount: "<<amount*0.85<<" EUR"<<endl;
  }
  else if (choice==2){
    cout<<"Converted amount: "<<amount*0.79<<" GBP"<<endl;
  }
  else if (choice==3){
    cout<<"Converted amount: "<<amount*146.41<<" JPY"<<endl;
  }
  else{
    cout<<"Invalid choice"<<endl;
  }
  return 0;
}