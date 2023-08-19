#include <stdio.h>
#include<stdlib.h>

int main(){
    int input,temp,i,sum=0;
    int digit[100];

    scanf("%d",&input);
    if (input<0){
        printf("Invalid");
        exit(0);
    }
    
    for(i=0 ; input!= 0;i++){
            digit[i] = input%10;
            input = input/10;
            }

    for(int j = 0; j<=i ; ++j){
        for(int k = j+1 ; k< i ; ++k){
           if (digit[j]>digit[k]){
               temp = digit[j];
               digit[j]=digit[k];
               digit[k]=temp;

           } 
        }
    }
    for (int m = 0 ; m<i ; m++){
        printf("%d\n",digit[m]);
    }
    for (int l = 0 ;l<(i)/2;l++){
        //printf("%d\n",sum);
        printf("i %d\n",i);
        sum += digit[i-l-1]+10*digit[l];
        printf("%d %d %d\n",sum,digit[i-l-1],digit[l]);

    }
    if (i%2 != 0){
        sum += digit[(i)/2];
    }
    printf("%d",sum);
}