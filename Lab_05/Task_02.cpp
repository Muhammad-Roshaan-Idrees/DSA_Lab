#include <iostream>
using namespace std;

// Define the structure for a node
struct Node
{
    int data; // Data to store
    Node* next; // Pointer to the next node
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData)
{
    // Allocate memory for a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

// Function to find the middle of the linked list
void findMiddle(Node* head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    Node* slow = head; // Slow pointer
    Node* fast = head; // Fast pointer

    // Move fast pointer two steps and slow pointer one step
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;        // Move slow pointer one step
        fast = fast->next->next;  // Move fast pointer two steps
    }

    // When fast pointer reaches the end, slow pointer is at the middle
    cout << "The middle of the linked list is: " << slow->data << endl;
}

// Function to print the linked list
void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    cout << "\n\n----------------------------- Lab 06 Linked List Implementation ______________________________________\n\n";
    Node* head = nullptr; // Initialize the head as NULL (empty list)
    int n, values;
    cout << "Enter the no of nodes in the list: " << endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout << "Enter the value "<<i+1<<endl;
        cin >> values;
        insertAtEnd(&head, values);
    }

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Find the middle of the linked list
    findMiddle(head);

    return 0;
}
