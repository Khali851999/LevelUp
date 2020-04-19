#include <iostream>
#include <vector>
#include <bitset>
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
    g[v].push_back(Edge(u, w));
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
//===================================================Basic===================================================================

//1-> mark
//2-> call for all unvisited neighbours
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
//================================================Paths===================================================================
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

    return 0;
}