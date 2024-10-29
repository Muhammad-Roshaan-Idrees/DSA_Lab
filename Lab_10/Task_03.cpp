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

// Function to search a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;

    if (value < root->data){
        return search(root->left, value);  // Search in the left subtree
    }else {
        return search(root->right, value); // Search in the right subtree
    }
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

    // Asking user to input a key to search in BST
    int key;
    cout<<"Enter the value to search: ";
    cin>>key;
    if(search(root, key)) {
        cout << key << " found in the BST.\n";
    }else {
        cout << key << " not found in the BST.\n";
    }

    return 0;
}
