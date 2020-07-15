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
int boardProblems()
{
    int n = 3, m = 3;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << ways_TD(0, 0, n - 1, m - 1, n, m, dp) << endl;
    display2D(dp);
    return ways_BU(0, 0, n - 1, m - 1, n, m, dp);
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
int stairProblem()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << climbStairs_TD(n, dp);
    display1D(dp);
    return climbStairs_BU(n, dp);
}

//======================================FRIENDS PAIRING==============================
// int pairing(int n)
// {

//     if (n <= 1)
//         return dp[n] = 1;

//     if (dp[n] != -1)
//         return dp[n];

//     int single = pairing(n - 1);
//     int pairUp = (n * 1) * pairing(n - 2);

//     return dp[n] = single + pairUp;
// }
//================================================GOLD MINE PROBLEM======================================
int goldMine_TD(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (j == m - 1)
        return dp[i][j] = grid[i][j];

    vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};
    int goldCollected = 0;
    for (int d = 0; d < 3; d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];

        if (r >= 0 && r < n && c >= 0 && c < m)
        {
            goldCollected = max(goldCollected, goldMine_TD(r, c, grid, dp));
        }
    }

    return dp[i][j] = goldCollected + grid[i][j];
}
int goldMineProblem()
{
    vector<vector<int>> grid = {{1, 3, 1, 5},
                                {2, 2, 4, 1},
                                {5, 0, 2, 3},
                                {0, 6, 1, 2}};

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxGoldCollected = 0;
    for (int i = 0; i < n; i++)
    {
        maxGoldCollected = max(maxGoldCollected, goldMine_TD(i, 0, grid, dp));
    }
    display2D(dp);
    return maxGoldCollected;
}
//===========================================n numbers in k subsets===================================
// int ways_to_partition_TD(int n, int k, vector<vector<int>> &dp)
// {

//     if (n <= k || k == 1)
//     {
//         if (n == k || k == 1)
//             return 1;

//         return 0;
//     }

//     int placeInKless1 = ways_to_partition_TD(n - 1, k - 1);
//     int placeInK = ways_to_partition_TD(n - 1, k);

//     return placeInKless1 + k * placeInK;
// }
// int ways_to_partition()
// {
//     int n = 10;
//     int k = 2;
//     vector<vector<int>> dp(n, vector<int>(k, -1));
//     return ways_to_partition_TD(n, k, dp);
// }
//=============================================substring ans subsequences===================================================
int longestPalindromeSubseq_TD(string &s, int l, int r, vector<vector<int>> &dp)
{

    if (l < 0 || r >= s.size() || l > r)
        return 0;

    if (l == r)
        return 1;

    if (dp[l][r] != 0)
        return dp[l][r];

    int len = 0;
    if (s[l] == s[r])

        len = longestPalindromeSubseq_TD(s, l + 1, r - 1, dp) + 2;

    else
    {

        len = max(len, longestPalindromeSubseq_TD(s, l + 1, r, dp));
        len = max(len, longestPalindromeSubseq_TD(s, l, r - 1, dp));
    }

    return dp[l][r] = len;
}
int longestPalindromeSubseq()
{
    string s = "geeksforgeeks";

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    longestPalindromeSubseq_TD(s, 0, n - 1, dp);

    display2D(dp);
    return dp[0][n - 1];
}
//===================================Longest Alternating Subs=================================================
int LongestAlternatingSubs(vector<int> &a)
{

    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(2, 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i])
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            else if (a[j] > a[i])
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        }
    }

    for (auto x : dp)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
}
int main()
{
    // cout<<boardProblems()<<endl;

    // vector<int> dp(11, -1);
    // cout << diceWays_TD(0, 10, dp) << endl;
    // display1D(dp);
    // cout << diceWays_BU(0, 10, dp) << endl;
    // display1D(dp);

    // cout<<stairProblem()<<endl;

    // cout << goldMineProblem();

    // cout << ways_to_partition() << endl;

    // cout << longestPalindromeSubseq() << endl;

    vector<int> arr = {10, 22, 9, 33, 49, 50, 31, 60};
    cout << LongestAlternatingSubs(arr);

    return 0;
}