#include <bits/stdc++.h>
using namespace std;
void display2D(vector<vector<int>> &arr)
{
    for (auto x : arr)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}
void display1D(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}

int MCM_TD(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{

    if (dp[si][ei] != -1)
        return dp[si][ei];

    if (si + 1 == ei)
        return dp[si][ei] = 0;

    int ans = INT_MAX;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM_TD(arr, si, cut, dp);
        int right = MCM_TD(arr, cut, ei, dp);
        int cost = left + arr[si] * arr[ei] * arr[cut] + right;
        ans = min(ans, cost);
    }

    return dp[si][ei] = ans;
}

int MCM_BU(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    int n = arr.size();
    for (int gap = 1; gap < n; gap++)
    {
        for (si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                continue;
            }
            int ans = INT_MAX;
            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = MCM_TD(arr, si, cut, dp);
                int right = MCM_TD(arr, cut, ei, dp);
                int cost = left + arr[si] * arr[ei] * arr[cut] + right;
                ans = min(ans, cost);
            }

            dp[si][ei] = ans;
        }
    }

    return dp[0][n - 1];
}
void MCM()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // MCM_TD(arr, 0, n - 1, dp);
    // display2D(dp);
    // MCM_BU(arr, 0, n - 1, dp);
    // display2D(dp);
}
int main()
{
    MCM();
    return 0;
}