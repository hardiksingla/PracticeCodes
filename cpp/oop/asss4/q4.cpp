#include <iostream>

class MathSymbol {
public:
    virtual int doOperation(int a, int b) const = 0;
};

class Plus : public MathSymbol {
public:
    int doOperation(int a, int b) const override {
        return a + b;
    }
};

class Minus : public MathSymbol {
public:
    int doOperation(int a, int b) const override {
        return a - b;
    }
};

int main() {
    Plus plusSymbol;
    Minus minusSymbol;

    int resultPlus = plusSymbol.doOperation(5, 3);
    std::cout << "5 + 3 = " << resultPlus << std::endl;

    int resultMinus = minusSymbol.doOperation(8, 3);
    std::cout << "8 - 3 = " << resultMinus << std::endl;

    return 0;
}
