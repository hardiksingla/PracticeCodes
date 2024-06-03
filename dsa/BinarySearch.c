#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
int main(){
  int *arr , n , key,mid;
  printf("Enter the size of the array: ");
  scanf("%d",&n);

  arr = (int *)malloc(n*sizeof(int));

  printf("Enter the elements of the array: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  printf("Enter the key to be searched: ");
  scanf("%d",&key);

  for(int i=0; i<n ; i++){
    for(int j =0 ; j<n ; j++){
      if (arr[i]<arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  int result = binarySearch(arr,n,key);

  if (result == -1){
    printf("Key not found\n");
  }else{
    printf("key was found at %d",result);
  }
  return 0;
}