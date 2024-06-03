#include <iostream>

using namespace std;

class computer {
protected:
  string companyName;
  double price;
public:
  computer(string companyName, double price){
    this->companyName = companyName;
    this->price = price;
  }
  void show(){
    cout << "Company Name: " << companyName << endl;
    cout << "Price: " << price << endl;
  }
};

class desktop : public computer {
protected:
  string color;
  double monitorSize;
  string processorType;

public:
  desktop(string companyName, double price,string color ,double monitorSize,string processorType)
    : computer(companyName, price){
      this->color = color;
      this->monitorSize = monitorSize;
      this->processorType = processorType;
      } 
  void show(){
    computer::show();
    cout << "Color: " << color << endl;
    cout << "Monitor Size: " << monitorSize << endl;
    cout << "Processor Type: " << processorType << endl;
  }
};

class laptop : public computer{
protected:
  string color;
  double size;
  double weight;
public:
  laptop(string companyName, double price, string color, double size, double weight)
    : computer(companyName, price){
      this->color = color;
      this->size = size;
      this->weight = weight;
    }
  void show(){
    computer ::show();
    cout << "Color: " << color << endl;
    cout << "Size: " << size << endl;
    cout << "Weight: " << weight << endl;
  }
};

class Aio : public laptop , public desktop{
protected:
  string quality;
public:
  Aio(string companyName, double price, string color, double size, double weight, string color1, double monitorSize, string processorType, string quality)
    : laptop(companyName, price, color, size, weight), desktop(companyName, price, color1, monitorSize, processorType){
      this->quality = quality;
    }
};


int main(){
  desktop d("HP", 50000, "Black", 15.6, "i5");
  laptop l("Dell", 60000, "Silver", 15.6, 2.5);
  d.show();
  cout << endl;
  l.show();
  return 0;
}