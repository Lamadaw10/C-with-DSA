//Problem-3
//WAP to find the factorial of the given number n!

#include <iostream>
using namespace std;

//Function to calculate the factorial of given number
int factorial(int n)
{
    //Checks if the number is equal to 0
    if (n == 0)
    {
        return 1;
    }
    //Calls the factorial function each time untill the n becomes 0
    int prevFactor = factorial(n-1);
    return n * prevFactor;
}

int main()
{
    int n;
    cout<<"Enter the number you want to get factorial of: ";
    cin>>n;

    //Calls the factorial function and prints the data
    cout<<factorial(n)<<endl;
    return 0;
}