#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* Right;
    int height;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->Right = NULL;
        this->height = 1;
    }
};

class AvL {
public:
    Node* root;

    AvL() {
        this->root = NULL;
    }

    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return root->height;
    }

    int getBalanceFactor(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return height(root->left) - height(root->Right);
    }

    // Right rotation
    Node* RightRotate(Node* root) {
        Node* x = root->left;
        Node* y = x->Right;

        // Perform rotation
        x->Right = root;
        root->left = y;

        // Update heights
        root->height = 1 + max(height(root->left), height(root->Right));
        x->height = 1 + max(height(x->left), height(x->Right));

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* root) {
        Node* x = root->Right;
        Node* y = x->left;

        // Perform rotation
        x->left = root;
        root->Right = y;

        // Update heights
        root->height = 1 + max(height(root->left), height(root->Right));
        x->height = 1 + max(height(x->left), height(x->Right));

        return x;
    }

    // Insert into AVL tree
    Node* insertAtAvl(int data, Node* root) {
        if (root == NULL) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insertAtAvl(data, root->left);
        } else if (data > root->data) {
            root->Right = insertAtAvl(data, root->Right);
        } else {
            return root; 
        }

        // Update height of current node
        root->height = 1 + max(height(root->left), height(root->Right));

        // Get the balance factor
        int balanceFactor = getBalanceFactor(root);

        // Balance the tree
        // Left Left Case
        if (balanceFactor > 1 && data < root->left->data) {
            return RightRotate(root);
        }

        // Right Right Case
        if (balanceFactor < -1 && data > root->Right->data) {
            return leftRotate(root);
        }

        // Left Right Case
        if (balanceFactor > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return RightRotate(root);
        }

        // Right Left Case
        if (balanceFactor < -1 && data < root->Right->data) {
            root->Right = RightRotate(root->Right);
            return leftRotate(root);
        }

        return root;
    }

    // Delete Node from AVL tree
    Node* maxroot(Node* main) {
        Node* root = main;
        while (root->Right != nullptr) {
            root = root->Right;
        }
        return root;
    }

    Node* delteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value > node->data) {
            node->Right = delteNode(node->Right, value);
        } else if (value < node->data) {
            node->left = delteNode(node->left, value);
        } else {
            // Node with no child
            if (node->left == nullptr && node->Right == nullptr) {
                delete node;
                return nullptr;
            }

            // Node with one child
            if (node->left == nullptr) {
                Node* temp = node->Right;
                delete node;
                return temp;
            } else if (node->Right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = maxroot(node->left);
            node->data = temp->data;
            node->left = delteNode(node->left, temp->data);
        }

        // Update height and balance the tree
        node->height = 1 + max(height(node->left), height(node->Right));
        int balance = getBalanceFactor(node);

        // Balance the tree
        if (balance > 1) {
            // Left Left Case
            if (getBalanceFactor(node->left) >= 0) {
                return RightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return RightRotate(node);
            }
        }

        if (balance < -1) {
            // Right Right Case
            if (getBalanceFactor(node->Right) <= 0) {
                return leftRotate(node);
            } else {
                node->Right = RightRotate(node->Right);
                return leftRotate(node);
            }
        }

        return node;
    }

    void remove(int val) {
        root = delteNode(root, val);
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->Right);
        }
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void add(int data) {
        root = insertAtAvl(data, root);
    }
};

int main() {
    AvL avl;

    avl.add(10);
    avl.add(20);
    avl.add(30);
    avl.add(40);
    avl.add(50);
    avl.add(25);

    cout << "Inorder traversal of the AVL tree: ";
    avl.inorder();

    cout << "Removing node 40..." << endl;
    avl.remove(40);

    cout << "Inorder traversal of the AVL tree: ";
    avl.inorder();

    return 0;
}
