//Advanced Recursion Problem-2
//WAF to count the number of paths possible from start point to end point in game board
#include <iostream>
using namespace std;

//Function to find the paths possible from start to end point in game board
int findPaths(int st, int en)
{
    //checks if the start is equal to end of game board
    if(st == en)
    {
        return 1;
    }
    //checks if the start is greater than end of game board
    if(st>en)
    {
        return 0;
    }
    int count = 0;
    //loop iterats to count the number of paths in board
    for(int i=1; i<=6; i++)
    {
        count += findPaths(st + i, en);
    }
    return count;
}

int main()
{
    cout<<findPaths(0, 3)<<endl;
    return 0;
}