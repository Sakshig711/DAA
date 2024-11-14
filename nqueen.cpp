#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,
               vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << endl;
        for (string row : ans[i])
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
