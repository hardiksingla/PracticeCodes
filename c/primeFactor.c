#include <stdio.h>
  
int main (){
    int number,k=0,j;
    while(1){
    printf("enter number");
    scanf("%d",&number);

    for(int i = 2; number!=1;i++){
        k=0;
        j = 2;
        for(j = 2;j<=i;j++){
            if(i%j==0){
                k++;
                //printf("%d",k);
            }
            
        }
        if(k == 1){
            while(number%i == 0){
                number = number/i;
                printf("%d\n",i);
            }
        }
    }
    }
    return 0;
}