#include <stdio.h>
int main(){
    int income;
    int tax;
    scanf("%d",&income);
    if (income<150001){
        printf("no tax");
    }
    else if (income<=300000 ){
        tax = (income-150000)*0.1;
        printf("%d",tax);
    }
    else if (income<=500000){
        tax = 150000*0.1 + (income-300000)*0.2;
        printf("%d",tax);
        }
    else {
        tax = 150000*0.1 + 300000*0.2 + (income - 450000)*0.3;
        printf("%d",tax);
        }

    
    
    return 0;
}