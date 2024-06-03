#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
};

struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void insertChild(struct TreeNode* parent, struct TreeNode* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        struct TreeNode* current = parent->firstChild;
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

void preOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRecursive(root->firstChild);
        preOrderRecursive(root->nextSibling);
    }
}

void preOrderNonRecursive(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[100];
    int top = -1;

    while (1) {
        while (root != NULL) {
            printf("%d ", root->data);
            if (root->nextSibling != NULL) {
                stack[++top] = root->nextSibling;
            }
            root = root->firstChild;
        }

        if (top == -1) break;

        root = stack[top--];
    }
}

void inOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        inOrderRecursive(root->firstChild);
        printf("%d ", root->data);
        inOrderRecursive(root->nextSibling);
    }
}

void postOrderRecursive(struct TreeNode* root) {
    if (root != NULL) {
        postOrderRecursive(root->firstChild);
        postOrderRecursive(root->nextSibling);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode* root = createTreeNode(1);
    struct TreeNode* child1 = createTreeNode(2);
    struct TreeNode* child2 = createTreeNode(3);
    struct TreeNode* child3 = createTreeNode(4);
    struct TreeNode* child4 = createTreeNode(5);

    insertChild(root, child1);
    insertChild(root, child2);
    insertChild(child1, child3);
    insertChild(child1, child4);

    printf("Pre-order Recursive: ");
    preOrderRecursive(root);
    printf("\n");

    printf("Pre-order Non-Recursive: ");
    preOrderNonRecursive(root);
    printf("\n");

    printf("In-order Recursive: ");
    inOrderRecursive(root);
    printf("\n");

    printf("Post-order Recursive: ");
    postOrderRecursive(root);
    printf("\n");

    return 0;
}
