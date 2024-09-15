//LeetCode Question-51
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int x, int y, int n)
{
   // Check the column
    for(int row = 0; row < x; row++)
    {
        if(board[row][y] == 'Q')
        {
            return false;
        }
    }

    // Check the upper left diagonal
    int row = x, col = y;
    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    // Check the upper right diagonal
    row = x, col = y;
    while(row >= 0 && col < n)
    {
        if(board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col++;
    }

    return true; // If no conflicts are found, return true
}

void solve(vector<string>& board, int x, int n, vector<vector<string>>& ans)
{
    if(x == n)
    {
        ans.push_back(board);
        return;
    }
    for(int col = 0; col < n; col++)
    {
        if(isSafe(board, x, col, n)) // Use 'x' instead of 'row'
        {
            board[x][col] = 'Q'; // Place the queen
            solve(board, x + 1, n, ans); // Recur to place the next queen
            board[x][col] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));    // Initialize the board
        solve(board, 0, n, ans);
        return ans;
    }

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> res = solveNQueens(n);
    /*
     // Print the results
    for(const auto& solution : res)
    {
        for(const auto& row : solution)
        {
            cout << row << endl; // Print each row of the solution
        }
        cout << endl; // Print a blank line between different solutions
    }
    */
    for(unsigned int i = 0; i < res.size(); i++)
    {
        for(unsigned int j = 0; j <res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}