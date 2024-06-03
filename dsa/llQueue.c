#include <stdio.h>
#include <stdlib.h>

struct Node* head = NULL;

struct Node {
    int data;
    struct Node* next;
};

void dequeue(){
  struct Node* temp = head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  printf("dequeued value is: %d\n",temp->next->data);
  temp->next=NULL;
}

void enqueue(int num){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = num;
    node->next = head;
    head = node;
}
void display(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
  int choice = 0;
  while (choice != 4){
    printf("enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit: ");
    scanf("%d", &choice);
    switch (choice){
      case 1:
        {
        int data;
        printf("enter data: ");
        scanf("%d", &data);
        getchar();
        enqueue(data);
        break;
        }
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      default:
        printf("invalid choice\n");
    }
  }
  return 0;
}