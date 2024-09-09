//BackTracking Problem - 1
//WAP to find a way for the rat in a maze to get out of using backtracking
#include <iostream>
using namespace std;
// Function to check if a particular cell is safe for the rat to move into
bool isSafe(int** arr, int x, int y, int n)
{
    // Check if the current position (x, y) is within bounds and has a value of 1 (open path)
    if(x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

// Backtracking function to solve the rat in a maze problem
bool ratInMaze(int** arr, int x, int y, int n, int** solArr)
{
    // Base case: if the rat has reached the bottom-right corner (n-1, n-1)
    if(x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;  // Mark the destination as part of the solution path
        return true;
    }
    
    // If the current cell (x, y) is safe to move into
    if(isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;  // Mark the current cell as part of the solution path
        
        // Move downwards in the x direction
        if(ratInMaze(arr, x + 1, y, n, solArr))
        {
            return true;  // If the path works, return true
        }

        // If moving down didn't work, move right in the y direction
        if(ratInMaze(arr, x, y + 1, n, solArr))
        {
            return true;  // If the path works, return true
        }
        
        // Backtracking: unmark the current cell (x, y) as it is not part of the solution path
        solArr[x][y] = 0;
        return false;  // Return false to explore other paths
    }
    return false;  // Return false if the current cell is not safe
}

int main()
{
    int n;
    cout << "Enter the size of square matrix: ";
    cin >> n;

    // Dynamic memory allocation for the maze matrix
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Input the maze matrix from the user (0 for blocked cell, 1 for open path)
    cout << "Enter the maze matrix (0 for blocked, 1 for open):\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Dynamic memory allocation for the solution matrix (initially all 0's)
    int** solArr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            solArr[i][j] = 0; // Initialize all cells of the solution matrix to 0
        }
    }

    // Solve the maze starting from the top-left corner (0, 0)
    if(ratInMaze(arr, 0, 0, n, solArr))
    {
        // If a solution is found, print the solution matrix
        cout << "Solution path:\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";  // Print each cell of the solution matrix
            }
            cout << endl;
        }
    }
    else
    {
        // If no solution exists, output a message indicating so
        cout << "No solution exists!" << endl;
    }

    // Deallocate the dynamically allocated memory for the maze and solution arrays
    for(int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}