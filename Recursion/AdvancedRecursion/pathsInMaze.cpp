//Advance Recursion Problem-3
//WAF to count the number of paths possible in a maze
#include <iostream>
using namespace std;

//Function to find number of paths in a maze
int countPath(int n, int i, int j)
{
    //Base case: If we are at the destination, return 1
    if(i == n-1 && j == n-1)
    {
        return 1;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }
    //Recursive case: Count the number of paths from the current position
    return countPath(n, i + 1, j) + countPath(n, i, j + 1);
}

int main()
{
    cout<<countPath(3, 0, 0)<<endl;
    return 0;
}