// C++ program to illustrate default
// constructor without 'explicit'
// keyword
#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:

	// Parameterized constructor
	explicit Complex(double r = 0.0, 
			double i = 0.0)
	{
    real = r;
    imag = i;
	}

	// A method to compare two 
	// Complex numbers
	bool operator == (Complex rhs)
	{
		return (real == rhs.real && 
				imag == rhs.imag);
	}
};

// Driver Code
int main()
{
	// a Complex object
	// Complex com1(3.0, 0.0);

	// if (com1 == Complex(3.0))
	// 	cout << "Same";
	// else
	// 	cout << "Not Same";

  string name;
  getline(cin,name);
  
  for (int i = 0 ; i<= name.length();i++){
    cout<<name[i]<<endl;
  }
	return 0;
}
