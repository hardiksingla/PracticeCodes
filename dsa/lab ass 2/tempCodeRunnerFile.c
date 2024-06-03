#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
int data;
struct TreeNode* left;
struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int data) {
TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
if (newNode) {
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
}
return newNode;
}
TreeNode* insert(TreeNode* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);
}
return root;
}
TreeNode* findMin(TreeNode* node) {
while (node->left != NULL) {
node = node->left;
}
return node;
}
TreeNode* deleteNode(TreeNode* root, int data) {
if (root == NULL) {

return root;
}
if (data < root->data) {
root->left = deleteNode(root->left, data);
} else if (data > root->data) {
root->right = deleteNode(root->right, data);
} else {
if (root->left == NULL) {
TreeNode* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
TreeNode* temp = root->left;
free(root);
return temp;
}
TreeNode* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}
TreeNode* search(TreeNode* root, int data) {
if (root == NULL || root->data == data) {
return root;
}
if (data < root->data) {
return search(root->left, data);
} else {
return search(root->right, data);
}
}
void inOrderTraversal(TreeNode* root) {
if (root == NULL) {
return;
}
inOrderTraversal(root->left);
printf("%d ", root->data);

inOrderTraversal(root->right);
}
int main() {
TreeNode* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);
printf("In-order traversal before deletions: ");
inOrderTraversal(root);
printf("\n");
int deleteValue = 20;
root = deleteNode(root, deleteValue);
printf("Deleted %d from the BST.\n", deleteValue);
printf("In-order traversal after deleting %d: ", deleteValue);
inOrderTraversal(root);
printf("\n");
int searchValue = 30;
TreeNode* searchResult = search(root, searchValue);
if (searchResult) {
printf("%d found in the BST.\n", searchValue);
} else {
printf("%d not found in the BST.\n", searchValue);
}
return 0;
}
