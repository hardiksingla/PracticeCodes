#include <iostream>

using namespace std;

class x {
public:
    x() {
        cout << "Constructor of x" << endl;
    }

    ~x() {
        cout << "Destructor of x" << endl;
    }
};

class y : public x {
public:
    y() {
        cout << "Constructor of y" << endl;
    }

    ~y() {
        cout << "Destructor of y" << endl;
    }
};

class z : public y {
public:
    z() {
        cout << "Constructor of z" << endl;
    }

    ~z() {
        cout << "Destructor of z" << endl;
    }
};

int main() {
    cout << "Creating an object of class z:" << endl;
    z obj;

    cout << "\nObject 'obj' is about to go out of scope:" << endl;

    return 0;
}
