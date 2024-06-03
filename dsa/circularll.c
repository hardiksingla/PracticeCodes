#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int num) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = num;
    node->next = node;
    return node;
}

struct Node* addNode(struct Node* head, int num) {
    struct Node* new = newNode(num);
    struct Node* temp = head;
    new->next = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new;
    return new;
}
struct Node* addEnd(struct Node* head , int num){
	struct Node* new = newNode(num);
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new;
	return head;
}
struct Node* addIndex(struct Node * head , int num , int index){
	struct Node* node = newNode(num);
	struct Node* temp = head;
	if(index==0){
		return addNode(head,num);
	}
	for (int i=0 ; i<index-1 ; i++){
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
	return head;
}
struct Node* delete(struct Node* head){	
  struct Node* temp = head;
  do{
    temp = temp->next;
  }while(temp->next != head);
  head = head->next;
  temp->next = head;
	return head;
}
struct Node* deleteIndex(struct Node* head,int index){
	if(index == 0){
		return delete(head);
	}
	struct Node* temp = head;
	for (int i = 0 ; i<index-1 ; i++){
		temp=temp->next;
	}
	temp->next = (temp->next)->next;
	return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    do{
        printf("%d ", head->data);
        head = head->next;
    }while(temp != head);
}

int main() {
    struct Node* node1 = newNode(1);
    node1 = addNode(node1, 2);
    node1 = addNode(node1, 3);
    node1 = addNode(node1, 4);
    node1 = delete(node1);
    display(node1);
    return 0;


    // printf("enter number: ");
		// int number;
		// scanf(" %d",&number);
		// getchar();		
		// struct Node* node1 = newNode(number);
		// printf("addNode : 0\n addEnd : 1\n addIndex : 2\n delete : 3\n deleteIndex : 4\n display : 5\n exit : 9\n");
		// int n=0, num, index;
		// while(n != 9){
		// 	printf(" \naddNode : 0\n addEnd : 1\n addIndex : 2\n delete : 3\n deleteIndex : 4\n display : 5\n exit : 9\n");			
		// 	scanf(" %d",&n);
		// 	getchar();
		// 	if(n==0){
		// 		int num;
		// 		printf("Enter the number : ");
		// 		scanf(" %d",&num);
		// 		getchar();
		// 		node1 = addNode(node1,num);
		// 	}
		// 	else if(n==1){
		// 		int num;
		// 		printf("Enter the number : ");
		// 		scanf(" %d",&num);
		// 		getchar();
		// 		node1 = addEnd(node1,num);
		// 	}
		// 	else if(n==2){
		// 		int num,index;
		// 		printf("Enter the number : ");
		// 		scanf(" %d",&num);
		// 		getchar();
		// 		printf("Enter the index : ");
		// 		scanf(" %d",&index);
		// 		getchar();
		// 		node1 = addIndex(node1,num,index);
		// 	}
		// 	else if(n==3){
		// 		node1 = delete(node1);
		// 	}
		// 	else if(n==4){
		// 		int index;
		// 		printf("Enter the index : ");
		// 		scanf(" %d",&index);
		// 		getchar();
		// 		node1 = deleteIndex(node1,index);
		// 	}
		// 	else if(n==5){
		// 		display(node1);
		// 	}
		// }

    return 0;
}
