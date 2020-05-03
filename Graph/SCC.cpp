#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 9
using namespace std;
void topologicalSort_(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<int> &ans)
{
    visited[src] = 1;
    for (auto x : graph[src])
    {
        if (!visited[x])
            topologicalSort_(graph, x, visited, ans);
    }
    ans.push_back(src);
}
int SCC_DFS(vector<vector<int>> &newGraph, int src, vector<bool> &vis, vector<int> &res)
{
    vis[src] = 1;
    int count = 0;
    for (auto x : newGraph[src])
    {
        if (!vis[x])
            count += SCC_DFS(newGraph, x, vis, res);
    }
    res.push_back(src);
    return count + 1;
}
int SCC(vector<vector<int>> &graph)
{
    vector<bool> vis(N, false);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            topologicalSort_(graph, i, vis, ans);
    }

    vector<vector<int>> newGraph(N, vector<int>());

    for (int i = 0; i < N; i++)
    {
        for (auto x : graph[i])
        {
            newGraph[x].push_back(i);
        }
    }

    vis.clear();
    vis.resize(N);
    vector<int> res;
    int noOfSCC = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (!vis[ans[i]])
        {
            noOfSCC++;
            int size = SCC_DFS(newGraph, ans[i], vis, res);
            for (int j = 0; j < size; j++)
                cout << res[j] << " ";
            cout << endl;
        }
    }

    return noOfSCC;
}
void addvertex(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
int main()
{
    vector<vector<int>> graph(N, vector<int>());
    addvertex(graph, 1, 2);
    addvertex(graph, 2, 3);
    addvertex(graph, 3, 1);
    addvertex(graph, 3, 4);
    addvertex(graph, 4, 7);
    addvertex(graph, 7, 6);
    addvertex(graph, 7, 8);
    addvertex(graph, 6, 5);
    addvertex(graph, 5, 4);

    for (int i = 0; i < N; i++)
    {
        for (auto x : graph[i])
            cout << x << " ";
        cout << endl;
    }
    cout << SCC(graph);
    return 0;
}
