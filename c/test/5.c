#include <stdio.h>

void swapValue(int num1,int num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
  printf("%d %d\n",num1,num2);
}

void swapReference(int* num1, int* num2){
  int temp = *num1;
  *num1 = * num2;
  *num2 = temp;

}

int main(){
  int num1,num2;
  printf("enter numbers: ");
  scanf("%d %d",&num1,&num2);
  swapValue(num1,num2);
  swapReference(&num1,&num2);
  printf("%d %d",num1,num2); 

}