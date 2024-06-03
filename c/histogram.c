#include<stdio.h>
#include <stdlib.h>

int main(){
    int count = 0;
    char ch ='q';
    int countArray[10]={0};
    FILE *file = fopen("ta.c","r");
    if (file == NULL){
        printf("error opening the file");
        exit(1);
    }
    while(ch != EOF){
        ch = fgetc(file);
        if (ch== 32 || ch==10){
            
            
            countArray[count -1]++;
            count = 0;
        }
        else{
            
            count++;
            
            
        }
    }
    for (int i=0 ; i<10 ; i++){
        //printf("%d  ->  %d\n", i+1,countArray[i] );
        printf("%d ->\t",i+1);
        for(int j = 0 ; j<countArray[i]; j++){
            printf("-");
        }
        printf("\n");

    }    
    return 0;


}