//LeetCode Problem -52
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle.
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int x, int y, int n)
{
    //Works for the column
    for(int row = 0 ; row < x; row++)
    {
        if(board[row][y] == 1)
        {
            return false;
        }
    }
    //Works for left diagonal
    int row = x;
    int col = y;
    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    //Works for right diagonal
    row = x;
    col = y;
    while(row >= 0 && col < n)
    {
        if(board[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

void solve(vector<vector<int>>& board, int x, int n, int& count)
{
    if(x == n)
    {
        count++; //counts the number of solutions
        return;
    }
    for(int col = 0 ; col < n; col++)
    {
        if(isSafe(board, x, col, n))
        {
            board[x][col] = 1; //places the queen 
            solve(board, x + 1, n, count); //recur to place the new queen
            board[x][col] = 0; //backtracks the position
        }
    }
}

int totalNQueens(int n)
{
    int count = 0; //initialize the count of the solutions
    vector<vector<int>> board(n, vector<int>(n, 0)); //initialize the board
    solve(board, 0, n, count); //starts solving from the first row
    return count; //return the total count of the solutions
}

int main()
{
    int n;
    cin >> n;
    cout << "The number of distinct solutions for the N-Queens puzzle is " << totalNQueens(n) << endl;
    return 0;
}