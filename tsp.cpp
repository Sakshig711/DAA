#include <bits/stdc++.h>
using namespace std;

const int N = 4;

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 25, 25},
    {15, 25, 0, 30},
    {20, 25, 30, 0}

};

int findMinEdge(int city)
{
    int minEdge = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (city != j && dist[city][j] < minEdge)
        {
            minEdge = dist[city][j];
        }
    }
    return minEdge;
}

int calculateBound(const vector<int> &path, int currentCost)
{
    int bound = currentCost;
    for (int i = 0; i < N; i++)
    {
        if (find(path.begin(), path.end(), i) == path.end())
        {
            bound += findMinEdge(i);
        }
    }
    return bound;
}

void tsp()
{
    stack<pair<vector<int>, int>> s;

    vector<int> bestPath;
    int bestCost = INT_MAX;

    vector<int> startPath = {0};
    int startCost = 0;

    s.push({startPath, startCost});

    while (!s.empty())
    {
        auto node = s.top();
        s.pop();
        vector<int> path = node.first;
        int currentCost = node.second;
        int currentBound = calculateBound(path, currentCost);

        if (currentBound >= bestCost)
            continue;

        if (path.size() == N)
        {
            int lastCity = path.back();
            int totalCost = currentCost + dist[lastCity][0];

            if (totalCost < bestCost)
            {
                bestCost = totalCost;
                bestPath = path;
            }
            continue;
        }

        for (int i = 0; i < N; i++)
        {
            if (find(path.begin(), path.end(), i) == path.end())
            {
                vector<int> childPath = path;
                childPath.push_back(i);
                int childCost = currentCost + dist[path.back()][i];
                int childBound = calculateBound(childPath, childCost);

                if (childBound < bestCost)
                {
                    s.push({childPath, childCost});
                }
            }
        }
    }

    cout << "Optimal Path: ";
    for (int city : bestPath)
    {
        cout << (char)('A' + city) << " ";
    }
    cout << "A" << endl;
    cout << "Minimum Cost : " << bestCost << endl;
}

int main()
{
    tsp();
    return 0;
}