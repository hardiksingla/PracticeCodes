#include <iostream>

using namespace std;

class Car {
private:
  string make;
  string model;
  int year;
  double rentalPrice;

public:
  Car(string make, string model, int year, double rentalPrice) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->rentalPrice = rentalPrice;
  }

  void setMake(string make) {
    this->make = make;
  }

  string getMake() {
    return make;
  }

  void setModel(string model) {
    this->model = model;
  }

  string getModel() {
    return model;
  }

  void setYear(int year) {
    this->year = year;
  }

  int getYear() {
    return year;
  }

  void setRentalPrice(double rentalPrice) {
    this->rentalPrice = rentalPrice;
  }

  double getRentalPrice() {
    return rentalPrice;
  }

  static double getTotalRentalPrice(Car cars[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
      total += cars[i].getRentalPrice();
    }
    return total;
  }

  static Car getHighestRentalPriceCar(Car cars[], int size) {
    Car highestCar = cars[0];
    for (int i = 1; i < size; i++) {
      if (cars[i].getRentalPrice() > highestCar.getRentalPrice()) {
        highestCar = cars[i];
      }
    }
    return highestCar;
  }
};

int main() {
  Car car1("Toyota", "Camry", 2018, 50.0);
  cout << "Make: " << car1.getMake() << endl;
  cout << "Model: " << car1.getModel() << endl;
  cout << "Year: " << car1.getYear() << endl;
  cout << "Rental Price: " << car1.getRentalPrice() << endl;

  Car cars[3] = { Car("Toyota", "Camry", 2018, 50.0),
                  Car("Honda", "Accord", 2019, 60.0),
                  Car("Ford", "Mustang", 2020, 80.0) };

  cout << "Total Rental Price: " << Car::getTotalRentalPrice(cars, 3) << endl;

  Car highestCar = Car::getHighestRentalPriceCar(cars, 3);
  cout << "Car with highest rental price: " << highestCar.getMake() << " " << highestCar.getModel() << endl;

  return 0;
}
