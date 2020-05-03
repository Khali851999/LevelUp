#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 7
using namespace std;
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
    // g[v].push_back(Edge(u, w));
}
void makeGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);
    addEdge(graph, 2, 5, 10);
}
void display(vector<vector<Edge>> &g)
{
    cout << "UNIDIRECTIONAL GRAPH" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i << "->";
        for (Edge e : g[i])
            cout << "(" << e.v << "," << e.w << ") ";
        cout << endl;
    }
    cout << endl;
}

//==========================================TOPOLOGICAL SORT==================================================================
void topologicalSort_(int src, vector<bool> &visited, vector<int> &ans)
{
    visited[src] = 1;
    for (auto x : graph[src])
    {
        if (!visited[x.v])
            topologicalSort_(x.v, visited, ans);
    }
    ans.push_back(src);
}

void topologicalSort()
{
    vector<int> ans;
    vector<bool> visited(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            topologicalSort_(i, visited, ans);
    }
    for (auto x : ans)
        cout << x << " ";
}

//leetcode 207 210
bool KahnAlgo(int num)
{

    vector<int> indegree(num, 0);

    for (auto x : graph)
    {
        for (auto y : x)
            indegree[y.v]++;
    }

    queue<int> q;
    for (int i = 0; i < num; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> ans;
    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            int val = q.front();
            q.pop();
            ans.push_back(val);

            for (auto x : graph[val])
            {
                if (--indegree[x.v] == 0)
                    q.push(x.v);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() == num)
    {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        return true;
    }
    return false;
}

int SCC_DFS(vector<vector<int>> &newGraph, int src, vector<bool> &vis, vector<int> &ans)
{
    vis[src] = 1;
    int count = 0;
    for (auto x : newGraph[src])
    {
        if (!vis[x])
            count += SCC_DFS(newGraph, x, vis, ans);
    }
    ans.push_back(src);
    return count;
}
int SCC()
{
    vector<bool> vis(N);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            topologicalSort_(i, vis, ans);
    }

    vector<vector<int>> newGraph(N, vector<int>());

    for (int i = 0; i < N; i++)
    {
        for (auto x : graph[i])
        {
            newGraph[x.v].push_back(i);
        }
    }

    vis.clear();
    vis.resize(N);
    vector<int> res;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (!vis[i])
        {
            int size = SCC_DFS(newGraph, i, vis, res);
            for (int i = 0; i < size; i++)
                cout << res[i] << " ";
            cout << endl;
        }
    }
}
int main()
{
    makeGraph();
    display(graph);
    // topologicalSort();
    cout << boolalpha << KahnAlgo(7);
}