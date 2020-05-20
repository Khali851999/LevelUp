#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <queue>
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
    addEdge(graph, 2, 5, 10);
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

//===============================================Dijisktra===================================================================
//1. source dependent
//2. min weight path to every vertex from a given source
//3. Makes Spanning Tree ( can be minimum or not)
class Node
{
public:
    int src, par, w, wsf;

    Node(int src, int par, int w, int wsf)
    {
        this->src = src;
        this->par = par;
        this->w = w;
        this->wsf = wsf;
    }
};
//for min pq
struct dComparator
{
public:
    bool operator()(Node &p1, Node &p2)
    {
        return p1.wsf > p2.wsf;
    }
};

void dijsktra(int src)
{
    // priority_queue<Node> pq;//max pq
    priority_queue<Node, vector<Node>, dComparator> pq; //min pq

    vector<bool> vis(N);
    pq.push(Node(src, -1, 0, 0));
    vector<vector<Edge>> dGraph(N, vector<Edge>());
    while (pq.size())
    {
        int size = pq.size();
        while (size--)
        {
            auto val = pq.top();
            pq.pop();

            if (vis[val.src] == 1)
                continue; //cycle

            if (val.par != -1)
                addEdge(dGraph, val.src, val.par, val.w);

            vis[val.src] = 1;
            for (auto x : graph[val.src])
            {
                if (!vis[x.v])
                    pq.push(Node(x.v, val.src, x.w, val.wsf + x.w));
            }
        }
    }
    display(dGraph);
}

int main()
{
    makeGraph();
    display(graph);
    dijsktra(0);
    return 0;
}

