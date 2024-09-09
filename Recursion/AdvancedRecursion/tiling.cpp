//Advanced Recursion Problem-4
//Given a 2xn board and tiles of size 2x1, count the number of ways to tile the given board using tiles
#include <iostream>
using namespace std;
// Recursive function to calculate the number of ways to tile a 2xn board
int tiling(int n)
{
    // Base cases
    if (n == 0) // No board to tile
    {
        return 0;
    }
    if (n == 1) // Only one way to tile a 2x1 board
    {
        return 1;
    }

    // Recursive relation: 
    // - tiling(n-1): if we place one vertical tile on the leftmost column, we are left with a (2 x (n-1)) board.
    // - tiling(n-2): if we place two horizontal tiles, we are left with a (2 x (n-2)) board.
    return tiling(n-1) + tiling(n-2);
}
int main()
{
    //Test the tiling function for a 2x4 board
    cout << "The total number of ways to tile the given board using tiles is " << tiling(4) << endl;
    return 0;
}