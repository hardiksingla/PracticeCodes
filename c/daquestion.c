#include<stdio.h>
#include<stdlib.h>




int main(){
    FILE *fp;
    int vowels=0,cosonents=0,space=0,tabs=0,special=0,number=0,lines=0;
    int ch;
    fp = fopen("ta.c","r");
    if (fp == NULL){
        printf("error opening the file");
        exit(1);
    }
    while(ch!=EOF){
        ch = fgetc(fp);
        if (ch>=48&&ch<=57){
            number++;
        }
        else if(ch=='\n'){
            lines++;
        }
        else if(ch==97||ch==101||ch==105||ch==111||ch==117||
                ch==65||ch==69 ||ch==73 ||ch==79 ||ch==85){
                    vowels++;
                }
        else if((ch>=65&&ch<=90)||(ch>=97&&ch>=112)){
            cosonents++;
        }
        else if(ch==9){
            tabs++;
        }
        else if(ch==32){
            space++;
        }
        
        else if(ch>=34&&ch<=64){
            special++;
        }
    }
    printf("vowels = %d\n",vowels);
    printf("consonents = %d\n",cosonents);
    printf("numbers = %d\n",number);
    printf("spaces = %d\n",space);
    printf("tabs = %d\n",tabs);
    printf("special = %d\n",special);
    printf("number of lines= %d",lines);


    return 0;

}