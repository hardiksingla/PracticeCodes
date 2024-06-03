#include <stdio.h>
#include <stdlib.h>

struct Node* head = NULL;

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(int num) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = num;
    node->next = head;
    head = node;
    return head;
}

struct Node* pop() {
    if (head == NULL) {
        printf("stack underflow\n");
        return head;
    }
    printf("popped element: %d\n", head->data);
    head = head->next;
    return head;
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
	int choice=0;

	while (choice != 4){
		printf("enter 1 to push, 2 to pop, 3 to display, 4 to exit: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				{
				int data;
				printf("enter data: ");
				scanf("%d", &data);
				getchar();
				head = push(data);
				break;
				}
			case 2:
				head = pop();
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
