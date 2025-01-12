#include<iostream>
using namespace std;
class node{
public:
int value;
node * left;
node * right;
node(int value){
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}
};
class bst{
    public:
    node * root;
    bst(){
        this->root=NULL;
    }
};
  void inorder(node * root){
        if(root==NULL){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->value<<"\t";
            inorder(root->right);
        }
    }
    // recursive apporach
    void insertion_r(node * & root,int value){
        // base case
        if(root==nullptr){
            node * newnode=new node(value);
            root=newnode; 
            return;
        }
        if(root->value>value){
            insertion_r(root->left,value);
        }
        else{
            insertion_r(root->right,value);
        }
        
    }
    // iteravtive approach
    void insertion_i(node * & root,int value){
        node * newnode=new node(value);
        if(root==NULL){
            root=newnode;
            return;
        }
        node * temp=root;
        while(true){
            if(temp->value>value){
                if(temp->left==nullptr){
                    temp->left=newnode;
                    return;
                }
                temp=temp->left;
            }
            else{
                if(temp->right==nullptr){
                    temp->right=newnode;
                    return;
                }
                temp=temp->right;
            }
        }
        
    }
    // Searching a value two apporach itterative and recursive
    string search(node * & root,int value){
        if(root == nullptr){
            return "not found"; // mean we have traversed till the last and unsuccessful
        }
        if(root->value == value){ // base case 1
            return "Found Successfully";
        }
        else if(root->value > value){
            return search(root->left, value);
        }
        else{
            return search(root->right, value);
        }
    }
     node * largestnodebst(node * root){
        // find the largest node 
        node * temp=root;
        while(temp->right!=nullptr){
            temp=temp->right;
        }
        return temp;
    }
    node * smallestnodebst(node * root){
        node * temp=root;
        while (temp->left!=nullptr)
        {
            temp=temp->left;
        }
        return temp;
    }
    node* deletbst(node* root, int key) {
    if (root == NULL) {
        return root; // Base case: tree is empty or key not found
    }

    // Traverse to find the node to be deleted
    if (key < root->value) {
        root->left = deletbst(root->left, key);
    } else if (key > root->value) {
        root->right = deletbst(root->right, key);
    } else {
        // Node found
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child (right child only)
        else if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: One child (left child only)
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 4: Two children
        else {
            // Find the in-order predecessor (largest in left subtree)
            node* justsmaller = largestnodebst(root->right);
            root->value = justsmaller->value; // Replace value with predecessor
            // Delete the in-order predecessor node
            root->left = deletbst(root->left, justsmaller->value);
        }
    }
    return root; // Return updated root
}

 int main()
{
    bst b1;
    insertion_r(b1.root,5);
    insertion_r(b1.root,4);
    insertion_r(b1.root,10);
    insertion_r(b1.root,3);
    insertion_r(b1.root,9);
    insertion_r(b1.root,8);
    inorder(b1.root);
    cout<<endl;
    cout<<search(b1.root,900)<<endl;
    cout<<search(b1.root,8)<<endl;
   // Create a BST instance
    int choice, value;

    do {
        cout << "\n----- Binary Search Tree Operations -----\n";
        cout << "1. Insert (Recursive)\n";
        cout << "2. Insert (Iterative)\n";
        cout << "3. Search\n";
        cout << "4. Delete a Node\n";
        cout << "5. Find Smallest Node\n";
        cout << "6. Find Largest Node\n";
        cout << "7. Display Inorder Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert using recursive approach
                cout << "Enter value to insert (Recursive): ";
                cin >> value;
                insertion_r(b1.root, value);
                break;

            case 2: // Insert using iterative approach
                cout << "Enter value to insert (Iterative): ";
                cin >> value;
                insertion_i(b1.root, value);
                break;

            case 3: // Search for a value
                cout << "Enter value to search: ";
                cin >> value;
                cout << search(b1.root, value) << endl;
                break;

            case 4: // Delete a node
                cout << "Enter value to delete: ";
                cin >> value;
                b1.root = deletbst(b1.root, value);
                break;

            case 5: { // Find the smallest node
                node* smallest = smallestnodebst(b1.root);
                if (smallest != nullptr) {
                    cout << "Smallest Node: " << smallest->value << endl;
                } else {
                    cout << "The tree is empty.\n";
                }
                break;
            }

            case 6: { // Find the largest node
                node* largest = largestnodebst(b1.root);
                if (largest != nullptr) {
                    cout << "Largest Node: " << largest->value << endl;
                } else {
                    cout << "The tree is empty.\n";
                }
                break;
            }

            case 7: // Display inorder traversal
                cout << "Inorder Traversal: ";
                inorder(b1.root);
                cout << endl;
                break;

            case 8: // Exit
                cout << "Exiting...\n";
                break;

            default: // Invalid choice
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 8);



    return 0;
}