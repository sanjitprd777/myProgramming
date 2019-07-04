THIS CODE HAS SOME FAULT
//DAG topological sort
#include <bits/stdc++.h>
#define MAX 100
#define ll long long int
#define initial 1
#define waiting 2
#define visited 3
using namespace std;
ll topo[MAX],k=0;
struct node{
    ll val;
};
struct edge{
    ll val=0;
};
struct graph{
    struct node nodes[MAX];
    struct edge adj[MAX][MAX];
};
struct graph create_graph(struct graph &g,ll node){
    ll i,edge,u,v;
    cout<<"Enter edges number : "<<endl;
    cin>>edge;
    for(i=0;i<edge;++i){
        cin>>u>>v;
        g.adj[u][v].val=1;
    }
    return g;
};
void topo_sort(struct graph &g,ll temp,ll node){
    topo[k++]=temp;
    g.nodes[temp].val=waiting;
    for(ll i=0;i<node;++i)
        if(g.adj[temp][i].val==1&&g.nodes[i].val==initial){
                    topo_sort(g,i,node);
        }
    g.nodes[temp].val=visited;
}
void dfs(struct graph &g,ll node){
    ll i;
    for(i=0;i<node;++i)
        g.nodes[i].val=initial;
    for(i=0;i<node;++i){
        if(g.nodes[i].val==initial)
            topo_sort(g,i,node);
    }
}
int main(){
    ll cnt=0,v,node,edge,i,topological[MAX];
    queue<ll> q;
    struct graph g;
    cout<<"Enter nodes number : "<<endl;
    cin>>node;
    g=create_graph(g,node);
    dfs(g,node);
    for(i=0;i<k;++i)
        cout<<topo[i]<<" ";
    return 0;
}

