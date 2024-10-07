//Implementation of stack
//Push(), Pop(), Top(), Empty()

#include <iostream>
using namespace std;
class stack{
    int* arr;
    int top;
public:
    //Constructor to initialize the stack
    stack()
    {
        arr = new int[0];
        top = -1;
    }
//Function to perform push operation in stack
    void push(int n)
    {
        if(top == n-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = n;
    }
//Function to perform pop opeartion in stack
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
//Function to perform top operation in stack
    int Top()
    {
        if(top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        return arr[top];
    }
//Boolean Function to check if the stack is empty or not
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();

    cout << st.empty() << endl;

    return 0;
}