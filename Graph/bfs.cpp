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

//=======================================================basic====================================================================
bool isCycle(int src, vector<int> &vis)
{
    queue<int> q;
    q.push(src);

    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            int top = q.front();
            q.pop();

            if(vis[top] == 1){
                return true;
            }

            vis[top] = 1;
            for(auto x: g[top]){
                if(!vis[x])
                    q.push(x);
            }

        }
        
    }

    return true;
    
}

bool cycle(){

    vector<int> vis(n, 0);
    bool ans = 0;
    for(int i=0;i<n;i++){
        if(!vis[i])
            ans = ans||isCycle(i,vis);
    }

    return ans;
}


//1. mark src
//2. for all unvisited neighbours
//   2.1 push in queue
void dfs()
{
}
bool isBipartite_(int src, vector<vector<Edge>> &g, vector<int> &visited)
{
    //0 for red 1 for green
    //pair(element,color)
    queue<pair<int, int>> q;
    q.push({src, 0});

    //visited array will keep the track of current color assigned to vertex
    //-1 for Unvisited; 0 for red; 1 for green
    visited[src] = 0;

    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            int ele = q.front().first;
            int clr = q.front().second;
            cout << ele << "->" << clr << endl;
            q.pop();

            //if element is already visited then its a cycle
            if (visited[ele] != -1)
            {
                //discrepancy as parent and child have same color
                if (visited[ele] != clr)
                    return false;
            }

            //1. mark src
            //2. for all unvisited neighbours
            //   2.1 push in queue
            visited[ele] = clr;
            for (auto x : g[ele])
            {
                //if the element is not visited yet or have different clr than only if can continue
                if (visited[x.v] == -1)
                    q.push({x.v, (clr + 1) % 2});
                else if (visited[x.v] !=(clr + 1) % 2)
                    return false;
            }
        }
    }
    return true;
}

//=================================================IS_BIPRATITE-LEETCODE 785==============================================
bool isBipartite()
{
    //visited array will keep the track of current color assigned to vertex
    vector<int> visited(N, -1);
    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == -1)
            res = res || isBipartite_(i, graph, visited);
    }
    return res;
}

int main()
{
    makeGraph();
    display(graph);
    cout << boolalpha << isBipartite();
    // dfs();
    return 0;
}
