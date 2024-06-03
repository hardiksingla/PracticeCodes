#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string name, double price){
      this->name = name;
      this->price = price;
    }

    virtual void display_info() const {
        cout << "Name: " << name << endl;
        cout << "Price: Rs " << price << endl;
    }
};

class Electronics : public Product {
private:
    string brand;

public:
    Electronics(string name, double price, string brand) : Product(name, price) {
        this->brand = brand;
    }

    void display_info() const override {
        Product::display_info();
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
private:
    string size;

public:
    Clothing(string name, double price, string size) : Product(name, price) {
        this->size = size;
}

    void display_info() const override {
        Product::display_info();
        cout << "Size: " << size << endl;
    }
};

int main() {
    Electronics laptop("nito", 100000, "acer");
    Clothing tshirt("shirt", 900, "medium");

    cout << "Electronics Product Information:" << endl;
    laptop.display_info();

    cout << "\nClothing Product Information:" << endl;
    tshirt.display_info();

    return 0;
}
