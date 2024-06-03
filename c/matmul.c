#include <stdio.h>
int main(){
    int r1,r2,c1,c2,sum;
    printf("enter mat 1 rows:\n");
    scanf("%d",&r1);
    printf("enter mat 1 column:\n");
    scanf("%d",&c1);
    printf("enter mat 2 rows:\n");
    scanf("%d",&r2);
    printf("enter mat 2 column:\n");
    scanf("%d",&c2);

    if (c1==r2){
    int array1[r1][c1],array2[r2][c2],array[r1][c2];
    printf("enter first matrix");
    for(int i =0;i<r1;i++){
        for(int j = 0;j<c1;j++){
           scanf("%d",&array1[i][j]);
        }
    }
    printf("%d\n",array1[r1-1][c1-1]);
    printf("enter second matrix");
    for(int i =0;i<r2;i++){
        for(int j = 0;j<c2;j++){
            scanf("%d",&array2[i][j]);
        }
    }
    for(int i = 0 ;i<r1;i++){
        for(int j = 0;j<c2;j++){
            sum =0;
            for(int k = 0;k<c1;k++){
                sum+= array1[i][k]*array2[k][j];
                
            }
            array[i][j]=sum;
        }
    }
    for(int i = 0;i<r1;i++){
        for(int j = 0;j<c2;j++){
            printf("   %d   ",array[i][j]);
        }
        printf("\n");
    }
}
    return 0;
}