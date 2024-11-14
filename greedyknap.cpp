#include <bits/stdc++.h>
using namespace std;
struct item
{
    int weight;
    int profit;
    double ratio;
};
bool compare(item a, item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<item> &items)
{
    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (auto item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            totalProfit += item.profit;
        }
        else
        {
            totalProfit += ((double)capacity / item.weight) * item.profit;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<item> item(n);

    cout << "Enter the weights and profits of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> item[i].profit >> item[i].weight;
        item[i].ratio = (double)item[i].profit / item[i].weight;
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    double maxProfit = fractionalKnapsack(capacity, item);
    cout << "The maximum profit is: " << maxProfit << endl;
    return 0;
}