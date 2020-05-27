#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
bool dfs(int src, vector<int> &vis, int clr)
{
    if (vis[src] != -1 && vis[src] != clr)
        return 0;
    vis[src] = clr;
    int ans = 1;
    for (auto x : g[src])
    {
        int clr1 = (clr + 1) % 2;
        if (vis[x] == -1)
            ans &= dfs(x, vis, clr1);
        if (vis[x] != clr1)
            return 0;
    }
    return ans;
}
bool isBipartite(int n, vector<vector<int>> &edges)
{
    g.resize(n, vector<int>());
    for (auto x : edges)
    {
        int u = x[0] - 1;
        int v = x[1] - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
        if (vis[i] == -1)
            if (!dfs(i, vis, 0))
                return 0;
    return 1;
    // bool res = 1;
    // for (int i = 0; i < n; i++)
    //     if (vis[i] == -1)
    //         res &= dfs(i, vis, 0);
    // return res;
}
int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {2, 4}};
    cout << isBipartite(5, edges);
}