#include <iostream>
#include <string>

using namespace std;

class Computer {
protected:
  string companyName;
  double price;
public:
  Computer(string companyName, double price) {
    this->companyName = companyName;
    this->price = price;
  }
  virtual void show() {
    cout << "Company Name: " << companyName << endl;
    cout << "Price: " << price << endl;
  }
};

class Desktop : public Computer {
private:
  string color;
  double monitorSize;
  string processorType;
public:
  Desktop(string companyName, double price, string color, double monitorSize, string processorType) : Computer(companyName, price) {
    this->color = color;
    this->monitorSize = monitorSize;
    this->processorType = processorType;
  }
  void show() override {
    Computer::show();
    cout << "Color: " << color << endl;
    cout << "Monitor Size: " << monitorSize << endl;
    cout << "Processor Type: " << processorType << endl;
  }
};

class Laptop : public Computer {
private:
  string color;
  double size;
  double weight;
  string processorType;
public:
  Laptop(string companyName, double price, string color, double size, double weight, string processorType) : Computer(companyName, price) {
    this->color = color;
    this->size = size;
    this->weight = weight;
    this->processorType = processorType;
  }
  void show() override {
    Computer::show();
    cout << "Color: " << color << endl;
    cout << "Size: " << size << endl;
    cout << "Weight: " << weight << endl;
    cout << "Processor Type: " << processorType << endl;
  }
};

int main() {
  Desktop *c1 = new Desktop("Dell", 1000, "Black", 15.6, "Intel Core i7");
  Laptop *c2 = new Laptop("Apple", 2000, "Silver", 13.3, 1.37, "Intel Core i5");

  c1->show();
  cout << endl;
  c2->show();

  return 0;
}
