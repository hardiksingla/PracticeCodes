#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct TreeNode* searchNode(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    }

    return searchNode(root->right, data);
}

// Function to display the BST using in-order traversal (sorted order)
void displayTree(struct TreeNode* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

void displayMenu() {
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert Node\n");
    printf("2. Delete Leaf Node\n");
    printf("3. Delete Node with One Child\n");
    printf("4. Delete Node with Two Children\n");
    printf("5. Search Node\n");
    printf("6. Display Tree (In-order Traversal)\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insertNode(root, data);
        } else if (choice == 2) {
            printf("Enter value to delete (leaf node): ");
            scanf("%d", &data);
            root = deleteNode(root, data);
        } else if (choice == 3) {
            printf("Enter value to delete (node with one child): ");
            scanf("%d", &data);
            root = deleteNode(root, data);
        } else if (choice == 4) {
            printf("Enter value to delete (node with two children): ");
            scanf("%d", &data);
            root = deleteNode(root, data);
        } else if (choice == 5) {
            printf("Enter value to search: ");
            scanf("%d", &data);
            struct TreeNode* found = searchNode(root, data);
            if (found != NULL) {
                printf("Node found in the BST.\n");
            } else {
                printf("Node not found in the BST.\n");
            }
        } else if (choice == 6) {
            printf("BST (In-order Traversal): ");
            displayTree(root);
            printf("\n");
        } else if (choice == 7) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
