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

//===============================================MAZEPATH-MULTIMOVES============================================
vector<vector<int>> dir = {{1, 0}, {0, 1}, {1, 1}};
int ways_TD(int sr, int sc, int er, int ec, int n, int m, vector<vector<int>> &dp)
{
    if (sr < 0 || sr >= n || sc < 0 || sc >= m)
        return 0;

    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    int count = 0;
    for (int d = 0; d < 3; d++)
    {
        for (int jump = 1; jump < min(n, m); jump++)
        {
            int r = sr + (dir[d][0] * jump);
            int c = sc + (dir[d][1] * jump);

            if (r < 0 || r >= n || c < 0 || c >= m)
                break;

            count += ways_TD(r, c, er, ec, n, m, dp);
        }
    }

    return dp[sr][sc] = count;
}

int ways_BU(int sr, int sc, int er, int ec, int n, int m, vector<vector<int>> &dp)
{

    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr < 0 || sr >= n || sc < 0 || sc >= m)
                break;

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            for (int d = 0; d < 3; d++)
            {
                for (int jump = 1; jump < min(n, m); jump++)
                {
                    int r = sr + (dir[d][0] * jump);
                    int c = sc + (dir[d][1] * jump);

                    if (r < 0 || r >= n || c < 0 || c >= m)
                        break;

                    count += dp[r][c];
                }
            }

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}
//=============================================DICEWAYS===============================================
int diceWays_TD(int start, int end, vector<int> &dp)
{
    if (start > end)
        return 0;

    if (start == end)
        return dp[start] = 1;

    if (dp[start] != -1)
        return dp[start];

    int ways = 0;
    for (int dice = 1; dice <= min(end - start, 6); dice++)
        ways += diceWays_TD(start + dice, end, dp);

    return dp[start] = ways;
}
int diceWays_BU(int start, int end, vector<int> &dp)
{

    for (start = end; start >= 0; start--)
    {

        if (start == end)
        {
            dp[start] = 1;
            continue;
        }

        int ways = 0;
        for (int dice = 1; dice <= min(end - start, 6); dice++)
            ways += dp[start + dice];

        dp[start] = ways;
    }

    return dp[0];
}
//=============================================================================================
int climbStairs_TD(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return dp[n] = 1;

    if (dp[n] != -1)
        return dp[n];

    int ways = climbStairs_TD(n - 1, dp) + climbStairs_TD(n - 2, dp);

    return dp[n] = ways;
}
int climbStairs_BU(int n, vector<int> &dp)
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {

        int ways = dp[i - 1] + dp[i - 2];
        dp[i] = ways;
    }

    return dp[n];
}
int minCostClimbingStairs(int i, vector<int> &cost)
{
    if (i > cost.size())
        return INT_MAX;

    if (i == cost.size())
        return 0;

    int amt1 = min(minCostClimbingStairs(i + 1, cost), minCostClimbingStairs(i + 2, cost));
    int amt2 = min(minCostClimbingStairs(i + 2, cost), minCostClimbingStairs(i + 3, cost));
    return min(amt1, amt2) + cost[i];
}
int main()
{
    // int n = 3, m = 3;
    // dp.resize(n, vector<int>(m, -1));
    // cout << ways_TD(0, 0, n - 1, m - 1, n, m) << endl;
    // display2D(dp);
    // cout << ways_BU(0, 0, n - 1, m - 1, n, m) << endl;
    // display2D(dp);

    // vector<int> dp(11, -1);
    // cout << diceWays_TD(0, 10, dp) << endl;
    // display1D(dp);
    // cout << diceWays_BU(0, 10, dp) << endl;
    // display1D(dp);

    int n = 10;
    vector<int> dp(n + 1, -1);
    // cout << climbStairs_TD(n, dp);
    // display1D(dp);
    cout << climbStairs_BU(n, dp);
    display1D(dp);
    return 0;
}