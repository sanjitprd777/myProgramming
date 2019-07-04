// prims algorithm space(V+E) , time(E*log(V))
#include <bits/stdc++.h>
#define ll long long int
#define MAX 100
#define NIL -1
#define infinity 999999999
#define initial 1
#define visited 2
using namespace std;
struct nodes{
    ll val=0;
};
struct arcs{
    ll val=0;
};
struct graph{
    struct nodes length[MAX];
    struct arcs arc[MAX][MAX];
    struct nodes state[MAX];
    struct nodes pre[MAX];
};
struct tree{
    ll u,v,wt=0;
};
struct graph create_graph(struct graph g,ll e){
    ll i,u,v,w;
    cout<<"Enter edges and corresponding weight"<<endl;
    for(i=0;i<e;++i){
        cin>>u>>v>>w;
        g.arc[u][v].val=w;
        g.arc[v][u].val=w;
    }
    return g;
};
ll min_node(struct graph g,ll n){
    ll i,m=infinity,curr=-1;
    for(i=0;i<n;++i)
        if(g.state[i].val==initial&&g.length[i].val<m){
            m=g.length[i].val;
            curr=i;
        }
    return curr;
}
void prims_algo(struct graph g,struct tree t[MAX],ll root,ll node){
    ll i,j,current,k=0;
    for(i=0;i<node;++i){
        g.state[i].val=initial;
        g.pre[i].val=NIL;
        g.length[i].val=infinity;
    }
    g.length[root].val=0;
    for(i=0;i<node;++i){
        current=min_node(g,node);
        g.state[current].val=visited;
        if(current!=root){
            t[k].u=g.pre[current].val;
            t[k].v=current;
            t[k].wt=g.arc[t[k].u][t[k].v].val;
            ++k;
        }
        for(j=0;j<node;++j){
            if(g.arc[current][j].val>0&&g.state[j].val==initial&&g.arc[current][j].val<g.length[j].val){
                g.pre[j].val=current;
                g.length[j].val=g.arc[current][j].val;
            }
        }
    }
}
int main(){
    ll root,n,e,w=0,i,j;
    struct graph g;
    cout<<"Enter number of nodes and edges"<<endl;
    cin>>n>>e;
    g=create_graph(g,e);
    cout<<"Enter root vertex"<<endl;
    cin>>root;
    struct tree t[MAX];
    prims_algo(g,t,root,n);
    for(i=0;i<n-1;++i){
        cout<<t[i].u<<" -> "<<t[i].v<<endl;
        w+=t[i].wt;
    }
    cout<<"Weight of tree is : "<<w<<endl;
    return 0;
}
