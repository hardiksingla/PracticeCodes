#include <stdio.h>
#include <stdlib.h>

struct Array{
  int *a;
  int length;
  int size;
};

void Display(struct Array arr){
  for (int i = 0; i< arr.length ; i++){
    printf("%d\n",arr.a[i]);
  }
}

int main(){
  struct Array arr;
  int n,i;
  printf("enter size of array: ");
  scanf("%d",&arr.size);
  getchar();
  printf("enter number of numbers: ");
  scanf("%d",&n);
  getchar();
  arr.a = (int*)malloc(100);
  arr.length=0;
  printf("enter all the elements");
  for (i=0;i<n;i++){
    scanf("%d",&arr.a[i]);
    getchar();
    arr.length++;
  }

  Display(arr);
  return 0;



}