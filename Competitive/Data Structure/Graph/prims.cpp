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
const ll N=9;
struct edge{
    ll u,v,w;
};
struct edge tree[N];
vector<pair<ll,ll>> v[N];
vector<ll> dis(N,inf),prd(N,nil),status(N,initial);
ll cnt=0;
void prims(ll root){
    ll x,y,i,j,w;
    dis[root]=0;
    pair<ll,ll> temp;
    set<pair<ll,ll>> s;
    s.insert(make_pair(dis[root],root));
    while(!s.empty()){
        temp=*(s.begin());
        x=temp.second;
        //cout<<x<<endl;
        s.erase(s.begin());
        status[x]=visited;
        if(x!=root){
            ++cnt;
            tree[cnt].u=prd[x];
            tree[cnt].v=x;
            tree[cnt].w=dis[x];
        }
        rep1(i,0,v[x].size()){
            if(status[v[x][i].first]==initial&&dis[v[x][i].first]>v[x][i].second){
               // cout<<v[x][i].first<<endl;
                if(dis[v[x][i].first]!=inf)
                    s.erase(s.find(make_pair(dis[v[x][i].second],v[x][i].first)));
                dis[v[x][i].first]=v[x][i].second;
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
        v[y].pb(make_pair(x,w));
    }
    ll root;
    cout<<"Enter a root vertex : ";
    cin>>root;
    prims(root);
    if(cnt!=N-1){
        cout<<"No spanning tree possible"<<endl;
        exit(1);
    }
    REP1(i,1,cnt)
        cout<<tree[i].u<<" -> "<<tree[i].v<<"  "<<tree[i].w<<endl;
    return 0;
}
