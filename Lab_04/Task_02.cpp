#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;   // Data to store
    Node* next; // Pointer to the next node
};

// Function to insert a node at the end
void insertAtEnd(Node** head, int newData) {
    // Allocate memory for new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to reverse the linked list
Node* reverseLinkedList(Node* head){
    if (head == NULL) {
        cout << "The list is empty. Cannot reverse." << endl;
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev to current
        current = next;        // Move to the next node
    }

    return prev;  // New head of the reversed list
}

// Function to print the linked list
void printList(Node* node) {
    if (node == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    while (node != nullptr) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "\n\n----------------Lab 06 Linked List Implementation ----------------------------------\n\n" << endl;

    // Initialize the head as NULL (empty List)
    Node* head = nullptr;

    int n, values, deleteValue;
    cout << "\nEnter the number of values you want in the linked list: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << endl;
        cin >> values;
        insertAtEnd(&head, values);
    }

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the linked list after reversing
    cout << "The Linked List after reversing is: ";
    printList(head);

    return 0;
}
