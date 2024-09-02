//Challenges-2
//WAP to print numbers till n in decreasing order and increasing order
#include <iostream>
using namespace std;

//Function prints the number in decreasing order
void dec(int n)
{
    if(n == 1)
    {
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}

//Function prints the number in increasing order
void inc(int n)
{
    if(n == 1)
    {
        cout<<"1"<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}

int main()
{
    int n;
    cout<<"Enter the numbers to find its decreasing and increasing order: ";
    cin>>n;

    dec(n);
    cout<<endl;
    inc(n);
    return 0;
}
