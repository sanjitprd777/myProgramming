#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define getchar_unlocked getchar
#define pb push_back
#define nil -1
#define initial 0
#define waiting 1
#define visited 2
#define inf 4e+9
using namespace std;
const ll N=5;
ll i,j,k,x,y,w,adj[N][N],wt[N][N],prd[N][N],dis[N][N];
int main(){
    cout<<"Enter the edges,weight and -1 -1 -1 to stop"<<endl;
    while(1){
        cin>>x>>y>>w;
        if(x==y&&y==w&&w==-1)
            break;
        adj[x][y]=1;
        wt[x][y]=w;
    }
    rep1(i,0,N)
        rep1(j,0,N){
            if(adj[i][j]==1){
                dis[i][j]=wt[i][j];
                prd[i][j]=i;
            }
            else{
                dis[i][j]=inf;
                prd[i][j]=nil;
            }
        }
    rep1(k,0,N)
        rep1(i,0,N)
            rep1(j,0,N){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    prd[i][j]=prd[k][j];
                }
            }
    ll src;
    cout<<"Enter a source vertex : ";
    cin>>src;
    rep1(i,0,N)
        if(i!=src)
            cout<<i<<"  "<<dis[src][i]<<endl;
    return 0;
}
