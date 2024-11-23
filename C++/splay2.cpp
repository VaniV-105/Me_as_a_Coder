#include <iostream>
#include <queue>

using namespace std;

// Node definition for the Splay Tree
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to perform right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to perform splay operation
Node* splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (root->key > key) {
        if (root->left == nullptr)
            return root;
        
        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (root->left->key < key) { // Zig-Zag (Left Right)
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        // Now perform rotation for root
        return (root->left == nullptr) ? root : rightRotate(root);
    } else {
        if (root->right == nullptr)
            return root;
        
        // Zag-Zag (Right Right)
        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        } else if (root->right->key < key) { // Zag-Zig (Right Left)
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Now perform rotation for root
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

// Function to insert a new key into the Splay Tree
Node* insert(Node* root, int key) {
    // If the tree is empty, create a new node
    if (root == nullptr)
        return createNode(key);

    // Perform splay to bring the key to the root
    root = splay(root, key);

    // If key is already present, return root
    if (root->key == key)
        return root;

    // Otherwise, allocate memory for the new node
    Node* newNode = createNode(key);

    // If the key is greater than the root, then new node becomes right child
    if (root->key < key) {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    } else { // If the key is smaller, new node becomes left child
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    }

    return newNode; // Return the new root
}

// Function to search for a key in the Splay Tree
Node* search(Node* root, int key) {
    return splay(root, key);
}

// Function to find the maximum node in the given tree
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    
    while (root->right != nullptr)
        root = root->right;
    
    return root;
}

// Function to delete a key from the Splay Tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    // Perform splay to bring the key to the root
    root = splay(root, key);

    // If the key is not present, return the root
    if (root->key != key)
        return root;

    // If the key is present, then delete it
    Node* leftSubtree = root->left;
    Node* rightSubtree = root->right;
    delete root;

    // If the left subtree is null, return the right subtree
    if (leftSubtree == nullptr)
        return rightSubtree;

    // Otherwise, find the maximum node in the left subtree
    Node* maxNode = findMax(leftSubtree);
    
    // Splay the maximum node to the root of the left subtree
    maxNode = splay(leftSubtree, maxNode->key);
    
    // Set the right subtree of the maximum node to be the right subtree
    // of the original root node
    maxNode->right = rightSubtree;
    
    return maxNode; // Return the new root
}

// Function to print the Splay Tree (BFS)
void BFS(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    cout << "BFS traversal of the Splay Tree: ";
    BFS(root);
    cout << endl;

    int searchKey = 40;
    root = search(root, searchKey);
    cout << "Splayed tree after searching key " << searchKey << ": ";
    BFS(root);
    cout << endl;

    int deleteKey = 50;
    root = deleteNode(root, deleteKey);
    cout << "Splayed tree after deleting key " << deleteKey << ": ";
    BFS(root);
    cout << endl;

    return 0;
}

