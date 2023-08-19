#include <iostream>
#include <string.h>


using namespace std;
using std :: string;


class Employee{
private:
  string name;
  string company;
  int age;
public:
  void setName(string name){
    this->name = name;
  }
  string getName(){
    return name;
  }
  void setCompany(string company){
    this->company = company;
  }
  string getCompany(){
    return company;
  }
  void setAge(int age){
    if (age >= 18)
    {
      this->age = age;
    }
  }
  int getAge(){
    return age;
  }
  void introduction(){
    cout << "Name: " << name << endl;
    cout << "Company: " << company << endl;
    cout << "Age: " << age << endl;
  }
  Employee(Employee &obj){
    cout << "Copy constructor called" << endl;
    name = obj.name;
    company = obj.company;
    age = obj.age;
  }
  Employee(string name, string company, int age){
    cout << "Constructor called" << endl;
    this->name = name;
    this->company = company;
    this->age = age;
  }
  Employee(){
    
    name = "No name";
    company = "No company";
    age = 0;
  }


};

int main(){
  Employee employee1("John", "Apple", 25);
  Employee employee2(employee1);
  employee2.introduction();

  return 0;
}