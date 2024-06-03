#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3 // Assuming order 3 for simplicity, actual order might be different

typedef struct BPlusTreeNode {
    int keys[MAX_KEYS];
    struct BPlusTreeNode *children[MAX_KEYS + 1];
    int numKeys;
    int isLeaf;
} BPlusTreeNode;

BPlusTreeNode *createNode() {
    BPlusTreeNode *node = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    for (int i = 0; i < MAX_KEYS; i++) {
        node->keys[i] = 0;
        node->children[i] = NULL;
    }
    node->children[MAX_KEYS] = NULL;
    node->numKeys = 0;
    node->isLeaf = 1;
    return node;
}

void splitChild(BPlusTreeNode *parent, int i, BPlusTreeNode *child) {
    // Create a new node which will store (t-1) keys of 'child'
    BPlusTreeNode *newNode = createNode();
    newNode->isLeaf = child->isLeaf;
    newNode->numKeys = MAX_KEYS / 2;

    // Copy the last (t-1) keys of 'child' to 'newNode'
    for (int j = 0; j < MAX_KEYS / 2; j++) {
        newNode->keys[j] = child->keys[j + MAX_KEYS / 2 + 1];
    }

    // Copy the last (t) children of 'child' to 'newNode'
    if (!child->isLeaf) {
        for (int j = 0; j <= MAX_KEYS / 2; j++) {
            newNode->children[j] = child->children[j + MAX_KEYS / 2 + 1];
        }
    }

    child->numKeys = MAX_KEYS / 2;

    // Insert a new child to parent node
    for (int j = parent->numKeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    // Move the middle key of 'child' up to the 'parent'
    for (int j = parent->numKeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[MAX_KEYS / 2];
    parent->numKeys = parent->numKeys + 1;
}

void freeTree(BPlusTreeNode *root) {
    if (root == NULL) return;
    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; ++i) {
            freeTree(root->children[i]);
        }
    }
    free(root);
}

void insertNonFull(BPlusTreeNode *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Insert new key into the appropriate position
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child which is going to have the new key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        if (node->children[i + 1]->numKeys == MAX_KEYS) {
            splitChild(node, i + 1, node->children[i + 1]);

            if (key > node->keys[i + 1]) {
                i++;
            }
        }
        insertNonFull(node->children[i + 1], key);
    }
}

void removeFromNode(BPlusTreeNode *node, int key) {
    int i = 0;
    while (i < node->numKeys && node->keys[i] < key) {
        i++;
    }

    if (i < node->numKeys && node->keys[i] == key) {
        // Shift all keys after i to the left
        for (int j = i + 1; j < node->numKeys; j++) {
            node->keys[j - 1] = node->keys[j];
        }
        node->numKeys--;
    } else {
        printf("Key not found.\n");
    }
}

void delete(BPlusTreeNode *root, int key) {
    if (!root) {
        printf("The tree is empty.\n");
        return;
    }

    BPlusTreeNode *current = root;
    while (!current->isLeaf) {
        int i = 0;
        while (i < current->numKeys && key > current->keys[i]) {
            i++;
        }
        current = current->children[i];
    }
    removeFromNode(current, key);
}

int search(BPlusTreeNode *root, int key) {
    // Traverse the nodes to find the key
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }
    if (i < root->numKeys && key == root->keys[i]) {
        return 1; // Key found
    }
    if (root->isLeaf) {
        return 0; // Key not found
    }
    return search(root->children[i], key);
}


void traverse(BPlusTreeNode *root) {
    // Implementing an inorder traversal as an example
    int i;
    for (i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->isLeaf) {
        traverse(root->children[i]);
    }
}


void insert(BPlusTreeNode **root, int key) {
    BPlusTreeNode *r = *root;
    if (r->numKeys == MAX_KEYS) {
        BPlusTreeNode *newNode = createNode();
        newNode->isLeaf = 0;
        newNode->children[0] = r;
        *root = newNode;
        splitChild(newNode, 0, r);
        insertNonFull(newNode, key);
    } else {
        insertNonFull(r, key);
    }
}

int main() {
    BPlusTreeNode *root = createNode();

    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int found = search(root, key);
                printf(found ? "Key found\n" : "Key not found\n");
                break;
            case 4:
                printf("Tree traversal:\n");
                traverse(root);
                break;
            case 5:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}