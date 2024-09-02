//Program-4
//WAP to print the nth fibonacci sequence of a number
#include <iostream>
using namespace std;

//Function to calculate the fibonacci sequence
int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int prevFib = fibonacci(n-1);
    int prevFib2 = fibonacci(n-2);
    return prevFib + prevFib2;
}

int main()
{
    int n;
    cout<<"Enter the number to find the nth fibonacci sequence: ";
    cin>>n;

    cout<<fibonacci(n)<<endl;
    return 0;
}