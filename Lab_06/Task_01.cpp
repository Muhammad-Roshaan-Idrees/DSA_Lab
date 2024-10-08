#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// --------------- Insert at Beginning ----------

void insertAtBeginning(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if(*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// --------------- Insert at any Position ----------

void insertAtPosition(Node **head, int newData, int position)
{
    if (*head == NULL)
    { 
    // If the list is empty, insert at the beginning 
    insertAtBeginning(head, newData);
    return; 
    }
    if (position < 1) 
    { 
        return; // Invalid position 
    }
    Node *current = *head;
    int count = 1;
    while (current != NULL && count < position) 
    {
       current = current->next; count++; 
    }
    if (current == NULL) 
    { // If the position is out of range, insert at the end
       insertAtEnd(head, newData); 
       return;
    } 
    Node *newNode = new Node(); 
    newNode->data = newData;
    if (current->prev != NULL) 
    {
        current->prev->next = newNode;
        newNode->prev = current->prev;
    }
    else 
    {
        *head = newNode;
        newNode->prev = NULL;
    }
    newNode->next = current; 
    current->prev = newNode; 
}

// --------------- Insert at End ----------

void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    Node* last = *head;
    newNode->data = newData;
    newNode->prev = NULL;
    if(*head == NULL)
    {
      newNode->prev = NULL;
      *head = newNode;
      return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// --------------- Delete from Beginning ----------

void deleteAtBeginning(Node **head)
{
    if (*head == NULL)
    {
        return; // List is empty
    }

    Node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    delete temp;
}

// --------------- Delete at any Position ----------

void deleteAtPosition(Node **head, int position)
{ 
    if (*head == NULL)
    {
        return; // List is empty 
    }
    if (position < 1)
    {
        return; // Invalid position
    }
    Node *current = *head; 
    int count = 1; 
    while (current != NULL && count < position) { current = current->next; count++; }
    if (current == NULL)
    {
        return; // Position out of range
    }
    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    }
    else 
    {
        *head = current->next;
    }
    if (current->next != NULL) 
    {
        current->next->prev = current->prev;   
    }
    delete current; 
}

// --------------- Delete from End ----------

void deleteAtEnd(Node** head)
{
    if(*head == NULL)
    return;
    Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    if(temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;    // This list had only one node
    }
    delete temp;
}

int main()
{

    Node * head = NULL;
// Testing Insertion Operations
    cout<<"Insert at the beginning of the list"<<endl;
    insertAtBeginning(&head, 12);
    cout<<"Insert at end of the list"<<endl;
    insertAtEnd(&head, 10);
    cout<<"Insert at end of the list"<<endl;
    insertAtEnd(&head, 20);
    cout<<"Insert at specific position of the list"<<endl;
    insertAtPosition(&head, 23, 4);
    cout<<"Insert at specific position of the list"<<endl;
    insertAtPosition(&head, 45, 2);
    
   // Testing Deletion Operations 
    cout<<"Delete at the begginng of the list"<<endl;
    deleteAtBeginning(&head);
    cout<<"Delete at specific position of the list"<<endl;
    deleteAtPosition(&head, 2);
    cout<<"Delete at the end of the list"<<endl;
    deleteAtEnd(&head);
    
    system("pause");
    
    return 0;
}
