#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#define N 7
using namespace std;

//===================================================Basic===================================================================

class Edge
{
public:
    int v = 0, w = 0;

    Edge(int v, int w)
    {
        this->w = w;
        this->v = v;
    }
};

vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(vector<vector<Edge>> &g, int u, int v, int w)
{
    g[u].push_back(Edge(v, w));
    g[v].push_back(Edge(u, w));
}
void makeGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    // addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);
    // addEdge(graph, 2, 5, 10);
}
void display(vector<vector<Edge>> &g)
{
    for (int i = 0; i < N; i++)
    {
        cout << i << "->";
        for (Edge e : g[i])
            cout << "(" << e.v << "," << e.w << ") ";
        cout << endl;
    }
    cout << endl;
}
int getIndex(int u, int v)
{
    //returns position of v in u
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i].v == v)
            return i;
    }
    return -1;
}
void removeEdge(int u, int v)
{
    int idx1 = getIndex(u, v);
    int idx2 = getIndex(v, u);

    if (idx1 >= 0)
        graph[u].erase(graph[u].begin() + idx1);

    if (idx2 >= 0)
        graph[v].erase(graph[v].begin() + idx2);
}

void removeVertex(int v)
{
    for (auto x : graph[v])
    {
        int idx = getIndex(x.v, v);
        if (idx >= 0)
            graph[x.v].erase(graph[x.v].begin() + idx);
    }
    graph[v].erase(graph[v].begin(), graph[v].end());
}

//================================================Paths===================================================================
//1-> mark
//2-> for all unvisited neighbours
//     2.1-> call dfs
bitset<32> visited(0);
int printAllPaths(int src, int des, string ans)
{
    if (src == des)
    {
        cout << ans << src << endl;
        return 1;
    }

    int c = 0;
    visited[src] = 1;
    for (auto x : graph[src])
    {
        if (!visited[x.v])
            c += printAllPaths(x.v, des, ans + to_string(src) + " ");
    }
    visited[src] = 0;

    return c;
}

class Node
{
public:
    int minval = 1e7, maxval = 0, floor = 0, ceil = 1e7;
};
int allInOne(int src, int des, Node &ans, int w, int data)
{
    if (src == des)
    {
        ans.maxval = max(ans.maxval, w);
        ans.minval = min(ans.minval, w);
        if (data < w)
            ans.ceil = min(ans.ceil, w);
        if (data > w)
            ans.floor = max(ans.floor, w);

        return 1;
    }

    int c = 0;
    visited[src] = 1;
    for (auto x : graph[src])
    {
        if (!visited[x.v])
            c += allInOne(x.v, des, ans, w + x.w, data);
    }
    visited[src] = 0;

    return c;
}

//=====================================================Hamitonian cycle=======================================================

void hamintonianCycle(int src, int osrc, int visited, int n, string ans)
{
    if (n == 1)
    {
        if (getIndex(osrc, src) == -1)
        {
            cout << "Path: " + ans + to_string(src) << endl;
        }
        else
        {
            cout << "Cycle: " + ans + to_string(src) << endl;
        }
        return;
    }

    int mask = (1 << src);
    visited ^= mask;

    for (auto x : graph[src])
    {
        int mask1 = (1 << x.v);
        if (!(visited & mask1))
        {
            hamintonianCycle(x.v, osrc, visited, n - 1, ans + to_string(src) + " ");
        }
    }
}

//========================================Get-Connected-Components=========================================================
int GCC_DFS(int vertex, int &vis)
{
    int size = 0;
    int mask = (1 << vertex);
    vis ^= mask;
    for (auto x : graph[vertex])
    {
        int mask1 = (1 << x.v);
        if (!(vis & mask1))
        {
            size += GCC_DFS(x.v, vis);
        }
    }
    return size + 1;
}

int GCC(int vertex)
{
    int vis = 0;
    int maxSize = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int mask = (1 << i);
        if (!(vis & mask))
        {
            maxSize = max(maxSize, GCC_DFS(i, vis));
        }
    }
    return maxSize;
}

//====================================================DISTINCT-ISLANDS-LEETCODE 860======================================================
unordered_map<string, bool> umap;

//RELATIVE COORDINATED METHOD
// string dfs_DistinctIslands(vector<vector<int>> &a, int &n, int &m, int i, int j, string &ans)
// {
//     if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size() || a[i][j] == 0)
//         return "";

//     a[i][j] = 0;
//     ans += to_string(i - n) + to_string(j - m) + "  ";
//     string res;
//     res += dfs_DistinctIslands(a, n, m, i + 1, j, ans) + "D";
//     res += dfs_DistinctIslands(a, n, m, i - 1, j + 1, ans) + "U";
//     res += dfs_DistinctIslands(a, n, m, i, j + 1, ans) + "R";
//     res += dfs_DistinctIslands(a, n, m, i, j - 1, ans) + "L";

//     return res;
// }

//STRING MOVE METHOD
string dfs_DistinctIslands(vector<vector<int>> &a, int &n, int &m, int i, int j, string ans)
{
    if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size() || a[i][j] == 0)
        return "b";

    a[i][j] = 0;

    string res = "";
    res += "D"+dfs_DistinctIslands(a, n, m, i + 1, j, ans);
    res += "U"+dfs_DistinctIslands(a, n, m, i - 1, j, ans);
    res += "R"+dfs_DistinctIslands(a, n, m, i, j + 1, ans);
    res += "L"+dfs_DistinctIslands(a, n, m, i, j - 1, ans);

    return res;
}
int countDistinctIslands(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                string ans;
                string s = dfs_DistinctIslands(a, i, j, i, j, ans);
                cout << s << endl;
                umap[s] = 1;
            }
        }
    }
    return umap.size();
}

int main()
{
    makeGraph();
    display(graph);
    // removeEdge(3, 4);
    // display(graph);
    // removeVertex(6);
    // display(graph);

    // printAllPaths(0,6,"");

    // Node ans;
    // cout << allInOne(0, 6, ans, 0, 20) << endl;
    // cout << ans.minval << ":" << ans.maxval << ":" << ans.ceil << ":" << ans.floor << endl;

    // hamintonianCycle(0, 0, 0, 7, "");

    //Get maximum sized connected component from multiple disconnected componenets
    // cout << GCC(0);

    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};

    cout << countDistinctIslands(grid) << endl;
    return 0;
}