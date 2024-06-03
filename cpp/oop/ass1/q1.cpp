#include <iostream>

using namespace std;

class class1{
  private:
    int a;
    public:
    class1(int a){
      this->a = a;
    }
    friend class class2;
};
class class2{
  private:
    int b;
    public:
    class2(int b){
      this->b = b;
    }
    void swap(class1 &obj1, class2 &obj2){
      int temp = obj1.a;
      obj1.a = obj2.b;
      obj2.b = temp;
    }
    void display(class1 &obj1, class2 &obj2){
      std::cout << "a = " << obj1.a << std::endl;
      std::cout << "b = " << obj2.b << std::endl;
    }
};
int main(){
  class class1 obj1(1);
  class class2 obj2(2);
  obj2.display(obj1, obj2);
  cout<<"after swapping"<<endl;
  obj2.swap(obj1, obj2);
  obj2.display(obj1, obj2);
}


