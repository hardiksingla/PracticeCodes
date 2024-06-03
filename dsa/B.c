#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3 // Order of the B Tree (t = 2 for simplicity)

typedef struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_KEYS + 1];
    int numKeys;
    bool isLeaf;
} BTreeNode;

BTreeNode *createNode() {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    for (int i = 0; i < MAX_KEYS; i++) {
        node->keys[i] = 0;
        node->children[i] = NULL;
    }
    node->children[MAX_KEYS] = NULL;
    node->numKeys = 0;
    node->isLeaf = true;
    return node;
}

// Functions to be implemented
void insert(BTreeNode **root, int key);
void delete(BTreeNode *root, int key);
int search(BTreeNode *root, int key);
void traverse(BTreeNode *root, int orderType); // 0: preorder, 1: inorder, 2: postorder
void splitChild(BTreeNode *parent, int i, BTreeNode *child);
void insertNonFull(BTreeNode *node, int key);

// Utility function to free memory
void freeTree(BTreeNode *root) {
    if (root == NULL) return;
    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; ++i) {
            freeTree(root->children[i]);
        }
    }
    free(root);
}


void splitChild(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *newNode = createNode();
    newNode->isLeaf = child->isLeaf;
    newNode->numKeys = MAX_KEYS / 2;

    for (int j = 0; j < MAX_KEYS / 2; j++) {
        newNode->keys[j] = child->keys[j + MAX_KEYS / 2 + 1];
    }

    if (!child->isLeaf) {
        for (int j = 0; j <= MAX_KEYS / 2; j++) {
            newNode->children[j] = child->children[j + MAX_KEYS / 2 + 1];
        }
    }

    child->numKeys = MAX_KEYS / 2;

    for (int j = parent->numKeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    for (int j = parent->numKeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[MAX_KEYS / 2];
    parent->numKeys++;
}

void insertNonFull(BTreeNode *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
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

void insert(BTreeNode **root, int key) {
    BTreeNode *r = *root;
    if (r->numKeys == MAX_KEYS) {
        BTreeNode *newNode = createNode();
        newNode->isLeaf = false;
        newNode->children[0] = r;
        *root = newNode;
        splitChild(newNode, 0, r);
        insertNonFull(newNode, key);
    } else {
        insertNonFull(r, key);
    }
}

int search(BTreeNode *root, int key) {
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

void traversePreOrder(BTreeNode *root) {
    if (!root) return;
    for (int i = 0; i < root->numKeys; i++) {
        printf("%d ", root->keys[i]);
    }
    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; i++) {
            traversePreOrder(root->children[i]);
        }
    }
}

void traverseInOrder(BTreeNode *root) {
    if (!root) return;
    int i;
    for (i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverseInOrder(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->isLeaf) {
        traverseInOrder(root->children[i]);
    }
}

void traversePostOrder(BTreeNode *root) {
    if (!root) return;
    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; i++) {
            traversePostOrder(root->children[i]);
        }
    }
    for (int i = 0; i < root->numKeys; i++) {
        printf("%d ", root->keys[i]);
    }
}

void traverse(BTreeNode *root, int orderType) {
    switch (orderType) {
        case 0: // Preorder
            traversePreOrder(root);
            break;
        case 1: // Inorder
            traverseInOrder(root);
            break;
        case 2: // Postorder
            traversePostOrder(root);
            break;
        default:
            printf("Invalid traversal order.\n");
    }
}

void deleteFromLeaf(BTreeNode *node, int keyIndex) {
    for (int i = keyIndex + 1; i < node->numKeys; ++i) {
        node->keys[i - 1] = node->keys[i];
    }
    node->numKeys--;
}

void deleteFromInternalNode(BTreeNode *node, int keyIndex) {
    int key = node->keys[keyIndex];

    // If the child that precedes key has at least t keys,
    // find the predecessor 'pred' of key in the subtree rooted at
    // child[keyIndex]. Replace key by pred. Recursively delete pred
    // in child[keyIndex]. This part is not implemented in this basic version.

    // If node has fewer than t keys, examine child[keyIndex+1].
    // If child[keyIndex+1] has at least t keys, find the successor 'succ' of key in
    // the subtree rooted at child[keyIndex+1]. Replace key by succ.
    // Recursively delete succ in child[keyIndex+1]. This part is not implemented in this basic version.

    // If both child[keyIndex] and child[keyIndex+1] have fewer than t keys, merge key and all of
    // child[keyIndex+1] into child[keyIndex], so that child[keyIndex] now contains 2t-1 keys.
    // Free child[keyIndex+1] and recursively delete key from child[keyIndex].
    // This part is not implemented in this basic version.

    // The actual deletion of the key in the internal node and handling the underflow is complex
    // and depends on the specific B-Tree properties and is not implemented here.
}

void delete(BTreeNode *root, int key) {
    if (!root) {
        printf("The tree is empty.\n");
        return;
    }

    BTreeNode *current = root;
    int i;
    while (!current->isLeaf) {
        for (i = 0; i < current->numKeys; i++) {
            if (key == current->keys[i]) {
                deleteFromInternalNode(current, i);
                return;
            } else if (key < current->keys[i]) {
                break;
            }
        }
        current = current->children[i];
    }

    for (i = 0; i < current->numKeys; i++) {
        if (key == current->keys[i]) {
            deleteFromLeaf(current, i);
            return;
        }
    }

    printf("Key not found.\n");
}

int main() {
    BTreeNode *root = createNode();

    int choice, key;
    printf("Enter the first element to insert: ");
    scanf("%d", &key);
    insert(&root, key);

    do {
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
                if (root == NULL || root->numKeys == 0) {
                    printf("The Tree is Empty\n");
                } else {
                    printf("Displaying tree (Inorder):\n");
                    traverse(root, 1); // Display using inorder traversal
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}

// Implement insert, delete, search, traverse, splitChild, and insertNonFull functions here
