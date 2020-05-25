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
    addEdge(graph, 3, 4, 2);
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
//===================================Articulation Point and Bridges (TARJANS ALGO)===========================================================
int Time = 0;
int rootCalls = 0;
vector<int> discovery(N, 0);
vector<int> know(N, 0);
vector<int> AP(N, 0);
vector<bool> vis(N, 0);
void dfs(int src, int par)
{
    vis[src] = 1;
    discovery[src] = know[src] = Time++;
    for (auto x : graph[src])
    {
        if (!vis[x.v])
        {
            if (par == -1)
                rootCalls++;

            dfs(x.v, src);
            if (discovery[src] <= know[x.v])
                AP[src]++;

            if (discovery[src] < know[x.v])
                cout << "Articulation Bridge from " << src << " to " << x.v << endl;

            know[src] = min(know[src], know[x.v]);
        }
        else if (x.v != par)
            know[src] = min(know[src], discovery[x.v]);
    }
}
void articulation()
{

    //If 2 or more calls are made by the src/rootnode then only it will be an artiulation point
    if (rootCalls == 1)
        AP[0]--;

    dfs(0, -1);
}
int main()
{
    makeGraph();
    display(graph);
    articulation();
    for (auto x : AP)
        cout << x << ":";
}