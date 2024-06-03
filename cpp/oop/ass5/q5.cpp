#include <iostream>

using namespace std;

template <typename T, int N>
T findMax(T (&arr)[N]) {
  T max = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int intArr[5];
  double doubleArr[5];
  
  cout << "Enter 5 integers: ";
  for (int i = 0; i < 5; i++) {
    cin >> intArr[i];
  }
  
  cout << "Enter 5 doubles: ";
  for (int i = 0; i < 5; i++) {
    cin >> doubleArr[i];
  }
  
  cout << "Max of intArr: " << findMax(intArr) << endl;
  cout << "Max of doubleArr: " << findMax(doubleArr) << endl;
  return 0;
}
