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

//TYPE 1 : DFS(can be valid or not)
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

//TYPE 2: BFS(Always valid if size is same)
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
//========================================Cycle in Directed Graph===================================================
bool topologiaclSortCycle_(int src, vector<int> vis, vector<int> &ans)
{ // faith: it will detect cycle.
    if (vis[src] == 1)
        return true; //cycle.
    if (vis[src] == 2)
        return false; // already visited vertex.gragph

    vis[src] = 1;
    bool res = false;
    for (auto e : graph[src])
        res = res || topologiaclSortCycle_(e.v, vis, ans);

    vis[src] = 2;
    ans.push_back(src);
    return res;
}

void topologiaclSortCycle()
{
    vector<int> vis(N, 0);
    vector<int> ans;

    bool res = false;
    for (int i = 0; i < N && !res; i++)
    {
        if (vis[i] == 0)
            res = res || topologiaclSortCycle_(i, vis, ans);
    }

    if (!res)
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << endl;
    else
        cout << "Cycle" << endl;
}

int main()
{
    makeGraph();
    display(graph);
    // topologicalSort();
    cout << boolalpha << KahnAlgo(7);
}