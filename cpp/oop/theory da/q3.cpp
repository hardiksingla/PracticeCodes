#include <iostream>
using namespace std;

void calSum(int* apples, int* oranges , int*sum) {
  *sum = *apples + *oranges;
}
void doubleSum(int* sum) {
  *sum *= 2;
}

int main() {
  int apples , oranges;
  int sum;
  
  cout << "Enter Apples: ";
  cin >> apples;
  cout << "Enter Oranges: ";
  cin >> oranges;

  calSum(&apples, &oranges, &sum);

  cout << "Sum: " << sum << endl;

  doubleSum(&sum);

  cout << "Double Sum: " << sum << endl;


  return 0;
}
