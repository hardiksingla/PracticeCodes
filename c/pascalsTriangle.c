#include <stdio.h>

int fact(int n){
    int ans = 1;
    for(int i=1 ; i<=n ;i++){
        ans = ans*i;
    }
    return ans;
}

int combination(int n ,int r){
    return(fact(n)/fact(n-r)/fact(r));
}

int main(){
    int rows;
    printf("enter number of rows");
    scanf("%d",&rows);
    
    for(int index = 0 ; index <= rows ; index++){
        for(int i = rows ; i>=index  ; i--){
            printf(" ");
        }
        
        for(int j = 0 ; j<= index ; j++){
        printf("%d ",combination(index,j));
        }
        printf("\n");
    }
    return 0;
}