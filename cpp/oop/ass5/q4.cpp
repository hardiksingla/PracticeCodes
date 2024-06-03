#include <iostream>

using namespace std;

template<typename T>
class Pair {
  T first;
  T second;
public:
  Pair(T f, T s) : first(f), second(s) {}
  T addition() const {
    return first + second;
  }
};

int main() {
  int a, b;
  cout << "Enter two integers: ";
  cin >> a >> b;
  Pair<int> p1(a, b);
  cout << "Sum of p1: " << p1.addition() << endl;

  double c, d;
  cout << "Enter two doubles: ";
  cin >> c >> d;
  Pair<double> p2(c, d);
  cout << "Sum of p2: " << p2.addition() << endl;

  return 0;
}
