#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    Person(){
        name = "";
        age = 0;
    }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void output() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollno;
    double marks;

public:
    Student(string name, int age, int rollno, double marks) : Person(name, age){
        this->rollno = rollno;
        this->marks = marks;
    }
    Student(): Person(){
        rollno = 0;
        marks = 0;
    }

    void input() {
        Person::input();
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void output() const {
        Person::output();
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: " << marks << endl;
    }
};

class Employee : public Person {
protected:
    int empcode;
    string designation;

public:
    Employee(string name, int age, int empcode, string designation) : Person(name, age){
        this->empcode = empcode;
        this->designation = designation;
    }
    Employee():Person(){
        empcode = 0;
        designation = "";
    }

    void input() {
        Person::input();
        cout << "Enter employee code: ";
        cin >> empcode;
        cout << "Enter designation: ";
        cin >> designation;
    }

    void output() const {
        Person::output();
        cout << "Employee Code: " << empcode << endl;
        cout << "Designation: " << designation << endl;
    }
};
int main() {
  Employee e1;
  e1.input();
  Student s1;
  s1.input();

  cout << "Employee Information:" << endl;
  e1.output();
  cout << "\nStudent Information:" << endl;
  s1.output();
  return 0;
}
