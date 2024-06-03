#include <iostream>
using namespace std;

int sumOfDivisors(int n) {
  int sum = 0;
  for (int i = 1; i <= n/2; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  const int LIMIT = 10000;
  int count = 0;
  for (int i = 1; i <= count < 50; i++) {
    int sum = sumOfDivisors(i);
    if (sum == i) {
      cout << i << " is a perfect number" << endl;
      count++;
    }
  }
  return 0;
}
