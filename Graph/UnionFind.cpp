#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> par;
void union_by_rank(){
    
}
int findPar(int vtx)
{
    if (par[vtx] == vtx)
        return vtx;
    par[vtx] = findPar(par[vtx]);
    return par[vtx];
}
int main()
{

    //Union Find Detect Cycle in Undirected Graph
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++)
        par.push_back(i);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        int p1 = findPar(u);
        int p2 = findPar(v);
        if (p1 == p2)
        {
            cout << "true" << endl;
            return 0;
        }
        par[p1] = p2;
    }
    cout << "false" << endl;
    return 0;
}
