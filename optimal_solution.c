#include <iostream>
#include <vector>

using namespace std;

void findCombination(vector<vector<int>>& ans, vector<int>& ds, int i, int n, int sum, int target, vector<int>& arr)
{
    if (i == n)
    {
        if (target == sum)
        {
            ans.push_back(ds); // Add the current combination to the answer
        }
        return;
    }

    // Taking the current element in the combination
    ds.push_back(arr[i]);
    findCombination(ans, ds, i + 1, n, sum + arr[i], target, arr);

    // Not taking the current element in the combination
    ds.pop_back();
    findCombination(ans, ds, i + 1, n, sum, target, arr);
}

int main()
{
    vector<int> arr = {200, 100, 50, 30, 20, 10, 5, 6, 4};
    int n = arr.size();

    vector<vector<int>> ans;
    vector<int> ds;

    int target = 320;

    findCombination(ans, ds, 0, n, 0, target, arr);

    for (vector<int>& temp : ans)
    {
        cout << "Solution: ";
        for (int num : temp)
        {
            cout << num << " "; // Print each element in the combination
        }
        cout << endl;
    }

    return 0;
}

