#include <iostream>

using namespace std;

class hero{
  int health;
  public:
    hero(){
      health = 100;
    }
    hero(hero &h){
      health = h.health * 2;
    }
    void setHealth(int h){
      health = h;
    }
    int getHealth(){
      cout << "health"<<health << endl;
    
    }
    ~hero(){
      cout << "destructor called"<<endl;
      this->getHealth();
    }
};
int main(){
  hero hero2;
  hero hero1;
  hero1.setHealth(50);

  hero1.getHealth();
  hero2.getHealth();
  return 0;
}