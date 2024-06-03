#include <iostream>

// Base class A
class A {
public:
    void display() {
        std::cout << "Class A display()" << std::endl;
    }
};

// Base class B
class B {
public:
    void display() {
        std::cout << "Class B display()" << std::endl;
    }
};

// Derived class from A and B
class C : public A, public B {
};

int main() {
    C cObj;
    
    // Error: Ambiguous function call
    cObj.A::display();

    return 0;
}
