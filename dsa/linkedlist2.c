#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};  

struct node *head = NULL;

void insert(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void delete() {
    struct node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("deleted value is: %d\n", temp->next->data);
    temp->next = NULL;
}

void display() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice = 0;
    while(choice != 4) {
        printf("enter 1 to insert, 2 to delete, 3 to display, 4 to exit: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                {
                    int data;
                    printf("enter data: ");
                    scanf("%d", &data);
                    getchar();
                    insert(data);
                    break;
                }
            case 2:
                delete();
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