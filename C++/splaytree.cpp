#include <iostream>
#include <string>

template <typename T>
class SplayTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node* parent;

        Node(const T& key, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
            : key(key), parent(parent), left(left), right(right) {}
    };

    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        if (y != nullptr)
            y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
        } else
            root = y;
        if (y != nullptr)
            y->left = x;
        if (x != nullptr)
            x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        if (y != nullptr)
            y->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
        } else
            root = y;
        if (y != nullptr)
            y->right = x;
        if (x != nullptr)
            x->parent = y;
    }

    void splay(Node* x) {
        while (x->parent) {
            Node* parent = x->parent;
            Node* grandParent = parent->parent;
            if (!grandParent) {
                if (x == parent->left)
                    rotateRight(parent);
                else
                    rotateLeft(parent);
            } else {
                if (x == parent->left) {
                    if (parent == grandParent->left) {
                        rotateRight(grandParent);
                        rotateRight(parent);
                    } else {
                        rotateRight(parent);
                        rotateLeft(grandParent);
                    }
                } else {
                    if (parent == grandParent->left) {
                        rotateLeft(parent);
                        rotateRight(grandParent);
                    } else {
                        rotateLeft(grandParent);
                        rotateLeft(parent);
                    }
                }
            }
        }
        root = x;
    }

    Node* search(Node* root, const T& key) {
        if (root == nullptr || root->key == key)
            return root;
        if (root->key < key)
            return search(root->right, key);
        return search(root->left, key);
    }

    void inOrder(Node* node, int depth) const {
        if (node != nullptr) {
            inOrder(node->right, depth + 1);
            std::cout << std::string(depth * 4, ' ') << node->key << std::endl;
            inOrder(node->left, depth + 1);
        }
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(const T& key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        Node* node = root;
        Node* parent = nullptr;

        while (node) {
            parent = node;
            if (key < node->key)
                node = node->left;
            else if (key > node->key)
                node = node->right;
            else // Key already exists
                return;
        }

        node = new Node(key, parent);
        if (key < parent->key)
            parent->left = node;
        else
            parent->right = node;

        splay(node);
    }

    bool find(const T& key) {
        if (!root)
            return false;

        Node* node = search(root, key);
        if (node) {
            splay(node);
            return true;
        }

        return false;
    }

    void remove(const T& key) {
        if (!root)
            return;

        Node* node = search(root, key);
        if (!node)
            return;

        splay(node);

        Node* leftSubtree = node->left;
        Node* rightSubtree = node->right;

        if (!leftSubtree && !rightSubtree) {
            delete node;
            root = nullptr;
            return;
        }

        if (!leftSubtree) {
            root = rightSubtree;
            rightSubtree->parent = nullptr;
            delete node;
            return;
        }

        if (!rightSubtree) {
            root = leftSubtree;
            leftSubtree->parent = nullptr;
            delete node;
            return;
        }

        Node* minRight = rightSubtree;
        while (minRight->left)
            minRight = minRight->left;

        minRight->left = leftSubtree;
        leftSubtree->parent = minRight;

        root = rightSubtree;
        rightSubtree->parent = nullptr;

        delete node;
    }

    void display() const {
        if (!root) {
            std::cout << "Empty tree." << std::endl;
            return;
        }
        std::cout << "Splay Tree Structure:" << std::endl;
        inOrder(root, 0);
    }
};

int main() {
    SplayTree<int> splayTree;

    int flag = 1, ch, n;
    while (flag) {
        std::cout << "Menu: Splay Tree:" << std::endl;
        std::cout << "1. Insertion" << std::endl;
        std::cout << "2. Deletion" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch (ch) {
            case 1:
                std::cout << "Enter the element to be inserted: ";
                std::cin >> n;
                splayTree.insert(n);
                break;
            case 2:
                std::cout << "Enter the element to be removed: ";
                std::cin >> n;
                splayTree.remove(n);
                break;
            case 3:
                splayTree.display();
                break;
            default:
                flag = 0;
                break;
        }
    }
    return 0;
}
