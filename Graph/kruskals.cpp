#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int u=0,v=0,w=0;
    edge(int a,int b,int c){
        u=a;
        v=b;
        w=c;
    }
};
bool comp(edge &e1,edge &e2){
    return e1.w<e2.w;
}
vector<int> par;
int findPar(int v){
    if(par[v]!=v)par[v]=findPar(par[v]);
    return par[v];
}
int kruskals(int n, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int v=g_from.size();
    vector<edge> g;
    for(int i=0;i<v;i++){
        g.push_back(edge(g_from[i],g_to[i],g_weight[i]));
        g.push_back(edge(g_to[i],g_from[i],g_weight[i]));
        
    }
    sort(g.begin(),g.end(),comp);
    for(int i=0;i<=v;i++)par.push_back(i);
    int sum=0;
    for(auto x:g){
        int p1=findPar(x.u);
        int p2=findPar(x.v);
        if(p1!=p2){
            sum+=x.w;
            par[p2]=p1;
            // cout<<x.u<<x.v<<x.w<<":";
        }
    }
    return sum;
}