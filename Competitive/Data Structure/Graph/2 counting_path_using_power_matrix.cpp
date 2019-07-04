//Computing path matrix from power of Adjacency Matrix
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define stop return 0
#define MAX 100
#define getchar_unlocked getchar
using namespace std;
ll choice;
ll adj[MAX][MAX]={0},path[MAX][MAX]={0},prod[MAX][MAX]={0},temp[MAX][MAX]={0};
void create_graph(ll &v){
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
        adj[origin][dest]=1;
        if(choice==1)
            adj[dest][origin]=1;
    }
}

void display_edge(ll v){
    cout<<"View of all edges in graph"<<endl;
    ll i,j;
    rep(i,0,v)
        cout<<"  V"<<i;
    cout<<endl;
    rep(i,0,v){
        for(j=0;j<v;++j){
            if(j==0)
                cout<<"V"<<i<<" ";
            cout<<adj[i][j]<<"   ";
        }
        cout<<endl;
    }
}
void multiply(ll v){
    ll i,j,k,t;
    rep(i,0,v){
        for(j=0;j<v;++j){
            temp[i][j]=0;
            for(k=0;k<v;++k)
              temp[i][j]+=prod[i][k]*adj[k][j];
        }
    }
    rep(i,0,v)
        for(j=0;j<v;++j)
            prod[i][j]=temp[i][j];
}
void add(ll v){
    ll i,j;
    rep(i,0,v)
        for(j=0;j<v;++j)
            path[i][j]+=prod[i][j];
}
int main()
{
    fast;
    ll x,v,i,j,k,origin,dest;
    cout<<"1 for undirected graph"<<endl<<"2 for directed graph"<<endl;
    cin>>choice;
    create_graph(v);
    rep(i,0,v)
        for(j=0;j<v;++j)
            prod[i][j]=path[i][j]=adj[i][j];

    REP(i,2,v){
        multiply(v);
        add(v);
    }

    cout<<endl<<"Number of path available"<<endl;
    rep(i,0,v){
        for(j=0;j<v;++j)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }

    rep(i,0,v)
        for(j=0;j<v;++j)
            if(path[i][j]!=0)
                path[i][j]=1;

    cout<<endl<<"Reachable path's"<<endl;
    rep(i,0,v){
        for(j=0;j<v;++j)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
    stop;
}
