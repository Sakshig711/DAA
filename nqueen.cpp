#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void displayBoard(vector<vector<int>> &queens, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (queens[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &queens, int row, int col, int n)
{
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (queens[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (queens[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (queens[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void placeQueens(int col, vector<vector<int>> &queens, int n)
{
    if (col == n)
    {
        displayBoard(queens, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(queens, row, col, n))
        {
            queens[row][col] = 1;
            placeQueens(col + 1, queens, n);
            queens[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> queens(n, vector<int>(n, 0));
    int solutionCount = 0;

    placeQueens(0, queens, n);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,
//                vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
//     {
//         if (col == n)
//         {
//             ans.push_back(board);
//             return;
//         }
//         for (int row = 0; row < n; row++)
//         {
//             if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
//             {
//                 board[row][col] = 'Q';
//                 leftRow[row] = 1;
//                 lowerDiagonal[row + col] = 1;
//                 upperDiagonal[n - 1 + col - row] = 1;

//                 solve(col + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

//                 board[row][col] = '.';
//                 leftRow[row] = 0;
//                 lowerDiagonal[row + col] = 0;
//                 upperDiagonal[n - 1 + col - row] = 0;
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
//         solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
//         return ans;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     Solution obj;
//     vector<vector<string>> ans = obj.solveNQueens(n);
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << "Arrangement " << i + 1 << endl;
//         for (string row : ans[i])
//         {
//             cout << row << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }
