//Doubly Linked List
//Insertion(Head & Tail) and Deletion(Head & Tail)
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//Function to insert at Head
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

//Function to insert at tail
void insertAtTail(node* &head, int val)
{
    if(head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

//Function to delete element from head
void deleteFromHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

//Function to delete element from tail
void deleteFromTail(node* &head, int pos)
{
    node* temp = head;
    int count = 0;

    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next == NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);

    deleteFromTail(head, 2);
    display(head);

    deleteFromHead(head);
    display(head);

    return 0;
}