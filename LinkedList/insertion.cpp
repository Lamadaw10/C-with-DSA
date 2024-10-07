//Some linked list problems solution
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

// Insertion at tail
void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Insertion at head
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Display the linked list
void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deletion(node* &head, int val)
{
    if (head == NULL) {
        // List is empty
        return;
    }

    //If the head node is the one to be deleted
    if (head->data == val) {
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    node* temp = head;
    while(temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

//Reversing the list
//Function reverse the list by iteration
node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

//Function reverse the list using recursion
node* reverseRecursion(node* &head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* newhead = reverseRecursion(head->next);
    
    head->next->next = head;
    head->next = NULL;

    return newhead;
}


int main()
{
    node* head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    display(head);

    insertAtHead(head, 1);
    display(head);

    //deletion(head, 3);
    //display(head);

    //node* newhead = reverse(head);
    //display(newhead);

    node* newhead = reverseRecursion(head);
    display(newhead);

    return 0;
}
