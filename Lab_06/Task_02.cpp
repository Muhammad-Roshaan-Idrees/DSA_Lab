#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void forwardTraversal()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseTraversal()
    {
        if (!tail)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << "-> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList doubl;
    int value;
    cout<<"Enter five elements in the list"<<endl;
    for(int i= 0; i<5; i++)
    {
        cout<<"Enter value "<<i+1<<" : ";
        cin>>value;
        doubl.insert(value);
    }

    cout<<"Traversal forward the double list"<<endl;
    doubl.forwardTraversal();
    cout<<"Traversal reverse the double list"<<endl;
    doubl.reverseTraversal();
    
    return 0;
    
}






