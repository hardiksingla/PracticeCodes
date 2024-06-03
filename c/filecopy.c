#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
    FILE *pa,*pb;
    char ch;
    pa = fopen("ta.c","r");
    if (pa == NULL){
        printf("can not open fa");
        exit(1);
    }
    pb = fopen("tb.c","w");
    if (pb == NULL){
        printf("can not open fb");
        exit(2);        
    }
    while(1){
        ch = fgetc(pa);
        //fprintf(pa,"%c","w");
        if (ch == EOF){
            break;
        }
        else{
            fputc(ch,pb);
        }

    }
    fclose(pa);
    fclose(pb);
    return 0;


}