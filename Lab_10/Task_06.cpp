#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

// Function to create a node
Node* createNode (int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a value
Node* insert (Node* root, int value){
    if (root == nullptr){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);
    }else if(value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
}

// Function ---  In-Order Traversal
void inOrderTraversal (Node* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);     // Visit left subtree
    cout << root->data << " ";        // Print the node's value
    inOrderTraversal(root->right);    // Visit right subtree
}

int main() {
    Node* root = nullptr;      // Start with an empty tree

        // Ask user to input values to insert nodes into the BST
    int n,val;
    cout << "Enter the number of values to insert: " << endl;
    cin>>n;
    for(int i = 0; i < n; i++)
      {
         cout<<"Enter the values for "<< i+1 << " node: ";
         cin>>val;
         root = insert(root, val);
      }

    // Display the unsorted array in ascending order in BST using inOrder Traversal
    cout << "In-Order Traversal of the BST: " << endl;
    inOrderTraversal(root);

    return 0;
}
