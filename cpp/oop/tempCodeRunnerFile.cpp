  employee(employee &obj){
    cout << "Copy constructor called" << endl;
    name = obj.name;
    company = obj.company;
    age = obj.age;
  }