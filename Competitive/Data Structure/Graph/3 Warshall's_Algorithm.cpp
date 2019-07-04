//Computing path matrix using WARSHALL'S Algorithm
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define stop return 0
#define MAX 100
using namespace std;
ll choice;
ll adj[MAX][MAX]={0},path[MAX][MAX]={0};
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

int main()
{
    fast;
    ll x,v,i,j,k,origin,dest;
    cout<<"1 for undirected graph"<<endl<<"2 for directed graph"<<endl;
    cin>>choice;
    create_graph(v);
    rep(i,0,v)
        rep(j,0,v)
            path[i][j]=adj[i][j];

    cout<<endl<<"Initial path's are : "<<endl;
    rep(i,0,v){
        rep(j,0,v)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }

    rep(k,0,v)
        rep(i,0,v)
            rep(j,0,v)
                path[i][j]=(path[i][j]||path[i][k]&&path[k][j]);

    cout<<endl<<"Reachable path's are : "<<endl;
    rep(i,0,v){
        rep(j,0,v)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
    stop;
}
