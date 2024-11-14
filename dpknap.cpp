#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int m, vector<int> &weights, vector<int> &profits)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= m; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m;

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> m;

    vector<int> weights(n), profits(n);
    cout << "Enter the weights of the items : ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the profits of the item : ";
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }
    int maxprofit = knapsack(n, m, weights, profits);
    cout << "The maximum profit is: " << maxprofit << endl;
    return 0;
}