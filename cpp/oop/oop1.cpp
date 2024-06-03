#include <iostream>
#include <string.h>
using namespace std;

class abstractEmployee
{
  virtual void getPromotion() = 0;
};

class Employee : abstractEmployee
{
private:
  string Company;
  int Age;

protected:
  string Name;


public:
  string getName()
  {
    return Name;
  }
  void setName(string name)
  {
    Name = name;
  }
  string getCompany()
  {
    return Company;
  }
  void setCompany(string company)
  {
    Company = company;
  }
  int getAge()
  {
    return Age;
  }
  void setAge(int age)
  {
    Age = age;
  }
  void introduction()
  {
    cout << Name << endl
         << Company << endl
         << Age << endl;
  }
  Employee(string name, string company, int age)
  {
    Name = name;
    Company = company;
    Age = age;
  }
  void getPromotion()
  {
    if (Age >= 30)
    {
      cout << Name << " gets a Promotion!";
    }
    else
    {
      cout << Name << " does not get Promotion!";
    }
  }
  virtual void work(){
    cout << "employee works"<<endl;
  }
};
class Developer : public Employee
{
public:
  string FavLanguage;
  Developer(string name, string company, int age, string favLanguage)
      : Employee(name, company, age){
        FavLanguage = favLanguage;
      }
  void fixBug(){
    cout<< Name << " fixed the bug using " << FavLanguage<<endl;
  }

};

int main()
{


  Developer dev1 = Developer("singla","google",20,"c++");

  dev1.introduction();
  dev1.fixBug();
  Employee * e1= &dev1;
  dev1.work();
  e1->work();


  return 0;
}