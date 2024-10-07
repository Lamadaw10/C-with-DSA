//Detecting cycle and making cycle in linked list
//Hare and Tortoise Algorithm
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//Inserting list at tail
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

//Firstly, creating a function that makes the linked list cycle
void makeCycle(node* &head, int pos)
{
    node* temp = head;
    node* startNode;

    int count = 0;
    while(temp->next != NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

//Secondly, creating boolean function to detect if the given list has a cycle
bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

//Display the linked list
void display(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main()
{
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    //makeCycle(head, 3);
    //display(head);

    cout << detectCycle(head) << endl;
    return 0;
}