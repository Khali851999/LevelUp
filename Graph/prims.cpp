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
//===============================================PRIMS=========================================================================
//1. src independent (MST)
//2. use prims when we have to make a graph    ||    use  kruskals when we dont have to make a graph

class Node
{
public:
    int src, par, w;

    Node(int src, int par, int w)
    {
        this->src = src;
        this->par = par;
        this->w = w;
    }
};
//for min pq
struct primsComparator
{
public:
    bool operator()(Node &p1, Node &p2)
    {
        return p1.w > p2.w;
    }
};

void prims(int src)
{
    // priority_queue<Node> pq;//max pq
    priority_queue<Node, vector<Node>, primsComparator> pq; //min pq

    vector<bool> vis(N);
    pq.push(Node(src, -1, 0));
    vector<vector<Edge>> dGraph(N, vector<Edge>());
    while (pq.maxsize())
    {
        int maxsize = pq.maxsize();
        while (maxsize--)
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
                    pq.push(Node(x.v, val.src, x.w));
            }
        }
    }
    display(dGraph);
}
int main()
{
    makeGraph();
    display(graph);
    prims(0);
    return 0;
}

#include <iostream>
using namespace std;
int det[5][5];
int mat[13][5];

void blast(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            det[r-i][j]=0;
            if(mat[i][j]==2)
            {
                det[r-i][j]=2;
                mat[i][j]=0;
            }
        }
    }
}

void unblast(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
        for(int j=0;j<5;j++)
        {
            if( det[r-i][j]==2)
                mat[i][j]=2;
        }
}
void calc(int n,int pos,int c,int &max)
{
    if(pos>4||pos<0||c<0)
        return;

    if(mat[n][pos]==2)
        c-=1;
    else if(mat[n][pos]==1)
        c+=1;

    if(n==0)
    {
        if(c>max)
            max=c;
        return;
    }
    else
    {
        calc(n-1,pos+1,c,max);
        calc(n-1,pos-1,c,max);
        calc(n-1,pos,c,max);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>mat[i][j];
        int max=-1,c;
        for(int j=0;j<5;j++)
            mat[n][j]=0;
        mat[n][2]=3;
        for(int j=n;j>=5;j--)
        {
            c=-1;
            blast(j-1);
            calc(n,2,0,c);
            if(c>max)
                max=c;
            unblast(j-1);
        }
        if(max<0)
            max=-1;
        cout<<max<<endl;
    }
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
#define maxsize 100001

vector<int> G[maxsize];
bool vis[maxsize];
int arr[maxsize];
int dep[maxsize];
int t=1;

void DFS(int src)
{
    vis[src]=true;
    arr[src]=t++;
    int i,v;
    for(i=0;i<G[src].maxsize();i++)
    {
        v=G[src][i];
        if(!vis[v])
        DFS(v);
    }    
    dep[src]=t++;
}

int main()
{
    int n,i,a,b,q,dir,d,s;
    cin>>n; //No. Of Houses In City
    for(i=0;i<n-1;i++)
    {
        vis[i]=false;
        arr[i]=0;
        dep[i]=0;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
    }
    for(i=0;i<n;i++)
    if(!vis[i])
    DFS(i);
    
    cin>>q; //No. of Queries
    for(i=0;i<q;i++)
    {
        cin>>dir>>d>>s;
        d--;s--;
        if(dir==0)
        {
            if(arr[s]>arr[d] && dep[s]<dep[d])
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        else
        {
            if(arr[s]<arr[d] && dep[s]>dep[d])
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
}
