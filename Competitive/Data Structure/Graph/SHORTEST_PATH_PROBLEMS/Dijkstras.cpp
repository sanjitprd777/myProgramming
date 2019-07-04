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
const ll N=8;
vector<pair<ll,ll>> v[N],v2[N];
vector<ll> dis(N,inf),prd(N,nil);
void dijkstra_algo(ll src){
    ll x,y,i,j,w;
    dis[src]=0;
    pair<ll,ll> temp;
    set<pair<ll,ll>> s;
    s.insert(make_pair(dis[src],src));
    while(!s.empty()){
        temp=*(s.begin());
        x=temp.second;
        s.erase(s.begin());
        rep1(i,0,v[x].size()){
            if(dis[v[x][i].first]>dis[x]+v[x][i].second){
                if(dis[v[x][i].first]!=inf)
                    s.erase(s.find(make_pair(dis[v[x][i].second],v[x][i].first)));
                dis[v[x][i].first]=dis[x]+v[x][i].second;
                s.insert(make_pair(dis[v[x][i].second],v[x][i].first));
                prd[v[x][i].first]=x;
            }
        }
    }
}
int main(){
    ll i,j,x,y,w;
    cout<<"Enter the edges,weight and -1 -1 -1 to stop"<<endl;
    while(1){
        cin>>x>>y>>w;
        if(x==y&&y==w&&w==-1)
            break;
        v[x].pb(make_pair(y,w));
        v2[y].pb(make_pair(x,w));
    }
    ll src;
    cout<<"Enter a source vertex : ";
    cin>>src;
    dijkstra_algo(src);
    rep1(i,0,N)
        cout<<i<<"   "<<dis[i]<<endl;
    return 0;
}
