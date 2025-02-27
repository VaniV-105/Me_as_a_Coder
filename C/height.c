#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int treeHeight(struct Node *root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        // Recursively calculate the height of left and right subtrees
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        // Return the maximum height of left or right subtree + 1 for the current node
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int main() {
    // Creating a sample binary tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int height = treeHeight(root);
    printf("Height of the tree is: %d\n", height);

    return 0;
}
