#include <iostream>

using namespace std;


float taylor (int x ,int n){
    static float num = 1.0 , den = 1.0 ;
    float r;
    if (n == 0){
        return 1.0;
    }
    r = taylor(x,n-1);
    num = num * x;
    den = den * n;
    return r + (num/den);
}

int main(){
    cout<< taylor(2,1111);
    return 0;
}
