#include <stdio.h>
#include <stdlib.h>

struct queue{
  int size;
  int length;
  int *arr;
};


int main(){
  struct queue queue1;
  int choice;
 
  printf("enter size of queue: ");
  scanf("%d", &queue1.size);

  queue1.arr = (int *)malloc(queue1.size * sizeof(int));

  printf("enter length of queue: ");
  scanf("%d", &queue1.length);
  
  printf("enter queue elements: ");
  for (int i = 0; i < queue1.length; i++){
    scanf("%d", &queue1.arr[i]);
  }

  printf("enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit: ");
  scanf("%d", &choice);

  while (choice != 4){
    switch (choice){
      case 1:
        if (queue1.length == queue1.size){
          printf("queue overflow\n");
        }
        else{
          int data;
          printf("enter data: ");
          scanf("%d", &data);
          queue1.arr[queue1.length] = data;
          queue1.length++;
        }
        break;
      case 2:
        if (queue1.length == 0){
          printf("queue underflow\n");
        }
        else{
          printf("dequeued element: %d\n", queue1.arr[0]);
          for (int i = 0; i < queue1.length - 1; i++){
            queue1.arr[i] = queue1.arr[i + 1];
          }
          queue1.length--;
        }
        break;
      case 3:
        if (queue1.length == 0){
          printf("queue is empty\n");
        }
        else{
          printf("queue elements: ");
          for (int i = 0; i < queue1.length; i++){
            printf("%d ", queue1.arr[i]);
          }
          printf("\n");
        }
        break;
      default:
        printf("invalid choice\n");
    }
    printf("enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit: ");
    scanf("%d", &choice);
  }
  return 0;
}