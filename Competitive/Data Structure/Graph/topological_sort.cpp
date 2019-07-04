//DAG topological sort
#include <bits/stdc++.h>
#define MAX 100
#define ll long long int
using namespace std;
struct node{
    ll val;
};
struct edge{
    ll val;
};
struct graph{
    struct node nodes[MAX];
    struct edge adj[MAX][MAX];
};
struct graph create_graph(struct graph g,ll node){
    ll i,edge,u,v;
    cout<<"Enter edges number : "<<endl;
    cin>>edge;
    for(i=0;i<edge;++i){
        cin>>u>>v;
        g.adj[u][v].val=1;
    }
    return g;
};
ll in_degree(struct graph g,ll node,ll v){
    ll i,ans=0;
    for(i=0;i<node;++i){
        if(g.adj[i][v].val==1)
            ++ans;
    }
    return ans;
}
int main(){
    ll cnt=0,v,node,edge,i,topological[MAX];
    queue<ll> q;
    struct graph g;
    cout<<"Enter nodes number : "<<endl;
    cin>>node;
    g=create_graph(g,node);
    for(i=0;i<node;++i){
        g.nodes[i].val=in_degree(g,node,i);
        if(g.nodes[i].val==0)
            q.push(i);
    }
    while(!q.empty()){
        v=q.front();  q.pop();
        topological[cnt++]=v;
        for(i=0;i<node;++i){
            if(g.adj[v][i].val==1){
                g.adj[v][i].val=0;
                g.nodes[i].val--;
                if(g.nodes[i].val==0)
                    q.push(i);
            }
        }
    }
    for(i=0;i<cnt;++i)
        cout<<topological[i]<<" ";
    return 0;
}
