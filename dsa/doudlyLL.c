#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};


struct node *head = NULL;

void insert(int data){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    struct node *temp1 = head;
    while(temp1->next != NULL){
      temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
  }
}

void delete(){
  struct node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
}

void print(){
  struct node *temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
} 

int main(){
  int choice,data;
  while(1){
    printf("1.Insert\n2.Delete\n3.Print\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter data: ");
        scanf("%d",&data);
        insert(data);
        break;
      case 2:
        delete();
        break;
      case 3:
        print();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}



