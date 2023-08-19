#include <stdio.h>
#include <string.h>

typedef struct book{
    int num;
    char flag;
    char name[100];
    char author[100];
    }book;

int add(book *b);
void display(book *b);
void author(struct book books[]);
void title(book books[]);


int main()
a{
    book lib[10];
    int number = 0,n,numb=0,bookCount=0,i;
    char input;
    printf("press <<a>> to add a book\npress <<d>> to display info about a book\npress <<w>> to list all the books from a author\npress <<n>> for number of books in library\npress <<i>> to issue a book\npress <<r>> to return a book\n");
    while (1){
    printf("Enter your choice:  ");
    scanf(" %c",&input);
    if (input=='a'&&number<10){
        add(&lib[number]);
        lib[number].num=++numb;
        number++;
        bookCount++;
    }
    else if (input == 'd'){
        printf("enter book number");
        scanf("%d",&n);
        display(&lib[--n]);
        }
    else if(input == 'w'){
        author(lib);
        }
    else if (input == 'n'){
        printf("%d\n",bookCount);
    }
    else if (input == 'i'){
        printf("enter book number: ");
        scanf("%d",&i);
        if (lib[i-1].flag=='u'){
            lib[i-1].flag='i';
            bookCount--;
            printf("book has been issued\n");
        }
        else {
            printf("book is already issued\n");
        }
        }
    else if (input == 't'){
        title(lib);
    }
    else if (input == 'r'){
    printf("enter book number: ");
        scanf("%d",&i);
        if (lib[i-1].flag=='i'){
            lib[i-1].flag='u';
            bookCount++;
            printf("book has been returned\n");
        }
        else {
            printf("book is not issued\n");
        }
        }
    }

    return 0;

}
int add(book *b)
{
    printf("name: ");
    scanf("%s",b->name);
    printf("author: ");
    scanf("%s",b->author);
    b->flag='u';

    return 0;
    }
void display(book *b){
    char *status;

    if(b->flag == 'i'){
        status = "issued";
    }
    else{
        status = "unissued";
    }

        printf("name: %s\nauthor: %s\nstatus: %s\nbook number; %d\n",b->name,b->author,status,b->num);
}
void author(book books[]){

    printf("enter name of the author: ");
    char name[100];
    scanf("%s",name);

        for (int i = 0 ; i <=10;i++){
            if (strcmp(books[i].author,name)==0){

                display(&books[i]);
            }
        }
}
void title(book books[]){
    printf("enter title: ");
    char name[100];
    int count=0;
    scanf("%s",name);

        for (int i = 0 ; i <=10;i++){
            if (strcmp(books[i].name,name)==0){
                count++;
                display(&books[i]);
            }

        }
        printf("there are %d books with title %s\n\n",count , name);
}
