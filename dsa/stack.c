#include <stdio.h>
#include <stdlib.h>

struct stack{
  int size;
  int length;
  int *arr;
};

void push(struct stack *stack1){
  if (stack1->length == stack1->size){
    printf("stack overflow\n");
  }
  else{
    int data;
    printf("enter data: ");
    scanf("%d", &data);
    stack1->arr[stack1->length] = data;
    stack1->length++;
  }
}

void pop(struct stack *stack1){
  if (stack1->length == 0){
    printf("stack underflow\n");
  }
  else{
    stack1->length--;
    printf("popped element: %d\n", stack1->arr[stack1->length]);
  }
}

void display(struct stack *stack1){
  if (stack1->length == 0){
    printf("stack is empty\n");
  }
  else{
    printf("stack elements: ");
    for (int i = 0; i < stack1->length; i++){
      printf("%d ", stack1->arr[i]);
    }
    printf("\n");
  }
}

int main(){
  struct stack stack1;
  int choice;
 
  printf("enter size of stack: ");
  scanf("%d", &stack1.size);

  stack1.arr = (int *)malloc(stack1.size * sizeof(int));

  printf("enter length of stack: ");
  scanf("%d", &stack1.length);
  
  printf("enter stack elements: ");
  for (int i = 0; i < stack1.length; i++){
    scanf("%d", &stack1.arr[i]);
  }

  while(1){
    printf("1. push\n2. pop\n3. display\n4. exit\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1){
      push(&stack1);
    }
    else if (choice == 2){
      pop(&stack1);
    }
    else if (choice == 3){
      display(&stack1);
    }
    else if (choice == 4){
      break;
    }
    else{
      printf("invalid choice\n");
    }
  }
  
}