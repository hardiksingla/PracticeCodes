#include <stdio.h>
#include <stdlib.h>

int main(){
    char *string , *substring;
    int num,num2,count=0;

    printf("enter thr length of string");
    scanf("%d",&num);
    string = (char*)malloc(num*sizeof(char));
    printf("enter thr length of substring");
    scanf("%d",&num2);
    substring = (char*)malloc(num2*sizeof(char));

    printf("enter string");
    for(int i=0 ; i<num ;i++ ){
        scanf("%c",&string[i]);
        getchar();
    }
    printf("enter substring");
    for(int i=0 ; i<num2 ; i++){
        scanf("%c",&substring[i]);
        getchar();
    }

    for(int j=0 ; j<num2 ; j++){
        for (int k=0 ; k<num ; k++){
            if(string[k]!=substring[j]){
                continue;
            }
            else{
                count++;
                
            }
        }
    }
    if (count == num2){
        printf("exist");
    }
    else{
        printf("does not exist");
    }


}