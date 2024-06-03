#include <stdio.h>
#include <strings.h>
#include <stdlib.h>


typedef struct qnode {
    int passport_number;
    char name[20];
    struct qnode* next;
} qnode;

void enqueue(qnode ** head , int * size){
  struct qnode * newNode = (qnode*) malloc (sizeof(qnode));
  
  printf("enter passport number: ");
  scanf("%d",&newNode->passport_number);
  // printf("enter name: ");
  // scanf("%s", newNode->name);
  newNode->next=NULL;
  struct qnode * temp = *head;

  if(*size>5){
    printf("queue full\n");
    return;
  }
  if (*head == NULL){
    *head = newNode;
    (*size)++;
  }else{
    while(temp->next != NULL){
      temp = temp->next;
      (*size)++;
    }
    temp->next = newNode;
  }
}


void dequeue(qnode ** head , int * size){
  qnode * temp = *head;
  
  if(*head == NULL){
    printf("queue empty\n");
    return;
  }
 
  printf("imigrating passanger: \n");
  printf("passport number: %d\n",temp->passport_number);
  // printf("passenger name %s\n",temp->name);

  *head = temp->next;
  (*size)--;

}

void display(qnode ** head){
    struct qnode * temp = *head;
    while (temp != NULL) {
        printf("passport number: %d\n", temp->passport_number);
        // printf("passenger name %s\n", temp->name);
        temp = temp->next;
    }
}



int main(){
  struct qnode * q1=NULL;
  struct qnode * q2=NULL;
  struct qnode * q3=NULL;
  int s1 = 0,s2=0,s3=0;

  enqueue(&q1,&s1);
  enqueue(&q1,&s1);
  enqueue(&q1,&s1);

  dequeue(&q1,&s1);

  enqueue(&q2,&s2);
  enqueue(&q2,&s2);
  enqueue(&q2,&s2);

  dequeue(&q1,&s1);
  dequeue(&q1,&s1);

  display(&q1);
  // display(&q2);

}