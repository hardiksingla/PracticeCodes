#include <stdio.h>
#include<stdlib.h>

void sort(int number[],int count){
   int temp;
   for(int i=0;i<count;i++){
      for(int j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }
}

int main(){
    int num1,num2;
    scanf("%d",&num1);
    int *arr1;
    int *arr2;
    arr1 = (int*)malloc(sizeof(int)*num1);
    
    for(int i=0 ; i<num1 ; i++){
        scanf("%d",arr1+i);
    }
    for(int i=0 ; i<num1 ; i++){
        printf("%d\n",*(arr1+i));
    }
    
    scanf("%d",&num2);
    arr2 = (int*)malloc(sizeof(int)*num2);
    
    sort(arr1,num1);
    sort(arr2,num2);
    
    
    int i = 0, j = 0;
    while (i < num1 && j < num2) {
        if (arr1[i] < arr2[j])
        printf("%d ",arr1[i++]);

        else if (arr2[j] < arr1[i])
        printf("%d ",arr2[j++]);

        else {
        printf("%d ",arr2[j++]);
        i++;
        }
    }
    
    
    return 0;
}


