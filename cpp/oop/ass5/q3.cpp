#include <iostream>
using namespace std;
template <typename T>
class value{
  public:
  T a,b;
  void swap() {
  T temp = a;
  a = b;
  b = temp;
}
};


int main() {
  value<int> v1;
  value<char> v2;

  cout << "Enter two integers: ";
  cin >> v1.a >> v1.b;

  cout << "Enter two characters: ";
  cin >> v2.a >> v2.b;
  cout << endl<<endl;


  cout << "Before swapping integers: " << v1.a << " " << v1.b << endl;
  v1.swap();
  cout << "After swapping integers: " << v1.a << " " << v1.b << endl<<endl;

  cout << "Before swapping characters: " << v2.a << " " << v2.b << endl;
  v2.swap();
  cout << "After swapping characters: " << v2.a << " " << v2.b << endl;

  return 0;
}
