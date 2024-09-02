// Recurion
// Problem-1
// WAP to add all numbers till n
#include <iostream>
using namespace std;

//Function to add all numbers till n
int sum(int n)
{
    //checks if n is equal to 0
    if(n == 0)
    {
        return 0;
    }
    //calls sum(n) function every time n becomes 0
    int prevSum = sum(n - 1);
    return n + prevSum;
}

int main()
{
    int n;
    cout<<"Enter the number to find the sum of it: ";
    cin>>n;
    //printing sum of the given number n by calling sum function
    cout<<sum(n)<<endl;
    return 0;
}
