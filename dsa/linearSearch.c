#include <stdio.h>
#include <stdlib.h>

int main(){
  int *arr , n , key;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  printf("Enter the elements of the array: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter the key to be searched: ");
  scanf("%d",&key);
  for(int i=0;i<n;i++){
    if(arr[i]==key){
      printf("Key found at index %d\n",i);
      return 0;
    }
  }
  printf("Key not found\n");
  return 0;
}