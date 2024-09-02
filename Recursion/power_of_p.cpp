//Problem-2
//WAP to calculate n raised to power of p
#include <iostream>
using namespace std;

//Function to calculate the power of a given number
int power(int n, int p)
{
    //checks if the power is queal to 0
    if (p == 0)
    {
        return 1;
    }
    //calls the function power untill the power becomes 0
    int prevPower = power(n,p-1);
    return n * prevPower;
}


int main()
{
    int n,p;
    cout<<"Enter the number to get the power of: ";
    cin>>n;
    cout<<"Enter the power you want: ";
    cin>>p;
    //calls the function and prints the power of given number
    cout<<power(n,p)<<endl;
    return 0;
}