//Adjacency Matrix of Graph
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false)
#define stop return 0
#define MAX 100
using namespace std;
struct arc{
    int val=0;
};
struct node{
    int nod;// no values are given to nodes, index itself is taken as nodes...
};
struct graph{
    struct arc adj[MAX][MAX];
    struct node nodes[MAX];
};
ll choice;
struct graph create_graph(struct graph g,ll &v){
    ll i,max_edge,origin,dest;
    cout<<"Enter number of vertices : "<<endl;
    cin>>v;
    if(choice==1)
        max_edge=(v*(v-1))/2;
    else
        max_edge=v*(v-1);

    rep(i,0,max_edge){
        cout<<"Enter -1 -1 to stop"<<endl;
        cin>>origin>>dest;
        if(origin==-1&&dest==-1)
            break;
        if(origin<0||origin>=v||dest<0||dest>=v){
            cout<<"Invalid edge"<<endl;
            i--;
            continue;
        }
        g.adj[origin][dest].val=1;
        if(choice==1)
            g.adj[dest][origin].val=1;
    }
    return g;
}
void insert_edge(struct graph &g,ll origin,ll dest,ll v){
    if(origin<0||origin>=v||dest<0||dest>=v){
        cout<<"Invalid edge!"<<endl;
        return;
    }
    g.adj[origin][dest].val=1;
    if(choice==1)
        g.adj[dest][origin].val=1;
    cout<<"Edge at "<<origin<<" "<<dest<<" is inserted"<<endl;
}
void delete_edge(struct graph &g,ll origin,ll dest,ll v){
    if(origin<0||origin>=v||dest<0||dest>=v){
        cout<<"Invalid edge!"<<endl;
        return;
    }
    if(g.adj[origin][dest].val==0){
        cout<<"Edge doesn't exits"<<endl;
        return;
    }
    g.adj[origin][dest].val=0;
    if(choice==1)
        g.adj[dest][origin].val=0;
    cout<<"Edge at "<<origin<<" "<<dest<<" is deleted"<<endl;
}
void display_edge(struct graph g,ll v){
    cout<<"View of all edges in graph"<<endl;
    ll i,j;
    rep(i,0,v)
        cout<<"  V"<<i;
    cout<<endl;
    rep(i,0,v){
        for(j=0;j<v;++j){
            if(j==0)
                cout<<"V"<<i<<" ";
            cout<<g.adj[i][j].val<<"   ";
        }
        cout<<endl;
    }
}
int main()
{
    fast;
    struct graph g;
    ll x,v,origin,dest;
    cout<<"1 for undirected graph"<<endl<<"2 for directed graph"<<endl;
    cin>>choice;
    g=create_graph(g,v);
    while(1){
        cout<<"1. To insert an edge"<<endl;
        cout<<"2. To delete an edge"<<endl;
        cout<<"3. To view all edge"<<endl;
        cout<<"0. exit"<<endl;
        cin>>x;
        switch(x){
            case 1: cout<<"Enter and edge to be inserted : "<<endl;
                    cin>>origin>>dest;
                    insert_edge(g,origin,dest,v);
                    break;
            case 2: cout<<"Enter and edge to be deleted : "<<endl;
                    cin>>origin>>dest;
                    delete_edge(g,origin,dest,v);
                    break;
            case 3: display_edge(g,v);
                    break;
            case 0: exit(0);
                    break;
        }
    }
    stop;
}
