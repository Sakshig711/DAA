#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> &arr, vector<int> &subset, int i, int sum, int target)
{
    if (sum == target)
    {
        cout << "{ ";
        for (int it : subset)
        {
            cout << it << " ";
        }
        cout << "}" << endl;
        return;
    }
    if (i == arr.size() || sum > target)
    {
        return;
    }
    subset.push_back(arr[i]);
    subsetSum(arr, subset, i + 1, sum + arr[i], target);

    subset.pop_back();
    subsetSum(arr, subset, i + 1, sum, target);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> subset;
    cout << "Subsets with sum " << target << " are:\n";
    subsetSum(arr, subset, 0, 0, target);

    return 0;
}
