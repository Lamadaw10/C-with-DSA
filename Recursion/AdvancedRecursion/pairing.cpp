//Advanced Recursion Problem - 5
//WAP to find number of ways in which n friends can remain single or can be paired up
#include <iostream>
using namespace std;

// Recursive function to find the number of ways friends can remain single or be paired
int pairing(int n)
{
    // Base cases
    if (n == 0 || n == 1) // No friends or only one friend (can only stay single)
    {
        return n;
    }
    if (n == 2) // Two friends can either stay single or form one pair
    {
        return 2;
    }

    // Recursive relation:
    // - pairing(n-1): if the nth friend stays single, we calculate the result for (n-1) friends.
    // - pairing(n-2) * (n-1): if the nth friend pairs with any of the (n-1) remaining friends, calculate the number of ways for (n-2) friends.
    return pairing(n-1) + pairing(n-2) * (n-1);
}

int main()
{
    //Test the pairing function with 4 friends
    cout << pairing(4) << endl;
    return 0;
}