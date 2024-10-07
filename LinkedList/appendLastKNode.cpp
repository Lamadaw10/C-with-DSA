//Append the last k nodes to start of the linked list
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

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
}

int length(node* &head)
{
    int l = 0;
    node* temp = head;
    while(temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node* kAppend(node* &head, int k)
{
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = length(head);
    k = k % l;
    int count = 0;
    while (tail->next != NULL )
    {
        if(count == l - k)
        {
            newTail = tail;
        }
        if(count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;    
    return newHead;
}

void display(node* &head)
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    for(int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head); //Before appending last k node

    node* newHead = kAppend(head, 4);
    display(newHead); //After appending last k node

    return 0;
}