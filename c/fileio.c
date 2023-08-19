#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 


int main(){
    char str[50];
    int integer;
    FILE * fptr;
    fptr = fopen("ta.c","w");
    if (fptr == NULL){
        printf("error");
        exit(1);
    }

    printf("enter string: ");
    gets(str);
    printf("enter integer: ");
    scanf("%d",&integer);
    fprintf(fptr,"%s\t%dtest",str , integer);

    return 0;

}