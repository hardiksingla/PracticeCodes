#include <stdio.h>

int prime(int num){
    for(int j =2 ; j<num; j++){
      if (num%j == 0){
        return 0;
      }
    }
    return 1;
}

int main(){
  int num1,num2;
  printf("enter numbers: ");
  scanf("%d %d",&num1,&num2);

  for(int i = num1 ; i<=num2  ; i++){
    if(prime(i)){
      printf("%d\n",i);
    }
  }
  return 0;

}