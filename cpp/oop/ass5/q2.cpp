#include <iostream>
#include <exception>

using namespace std;

int main() {
  int x, y, z, R;
  cout << "Enter three numbers: ";
  cin >> x >> y >> z;
  try {
    if (y == 0) {
      throw runtime_error("Division by zero is not allowed.");
    }
    R = z * (x - y);
    cout << "R = " << R << endl;
  }
  catch (const exception& e) {
    cout << "Exception: " << e.what() << endl;
  }
  return 0;
}
