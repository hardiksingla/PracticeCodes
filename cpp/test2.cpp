#include <iostream>

using namespace std;

typedef struct array{
    int *array;
    int size;
    int length;

} array;

void display (array a);



int main(){
    struct array arr1;
    cout<< "enter size of the array\n";
    cin>> arr1.size;
    cout<< arr1.size;
    arr1.array = new int[arr1.size];

    cout<< "enter number of elements\n";
    cin>> arr1.length;
    cout<< "enter all the elements\n";
    for (int i = 0; i <arr1.length; i++){
        cin>> arr1.array[i];

    } 
    display(arr1);
    cout<< sizeof(arr1.array);
    

    return 0;

}
void display (array a){
    for (int i = 0 ; i < a.length ; i++){
        cout<< a.array[i];
    }
}