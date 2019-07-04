#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define initial 1
#define waiting 2
#define visited 3
#define nil -1
#define inf 7e+9
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;

vector<pair<ll,ll>> edges;
vector<pair<ll,ll>> v[200050];
ll par[200050],vis[200050],low[200050],isbridge[200050]={0};
void dfs_bridge(ll st,ll timer,ll status[200050]){
    status[st]=visited;
    vis[st]=low[st]=timer+1;
    ll i,t;
    rep(i,0,v[st].size()){
        t=v[st][i].first;
            if(status[t]==initial){
                par[t]=st;
                dfs_bridge(t,timer+1,status);
                if(vis[st]<low[t])  //to find articulation point replace '<' by '<='
                    isbridge[v[st][i].second]=1;
                low[st]=min(low[t],low[st]);
            }
            else if(par[st]!=t)
                low[st]=min(vis[t],low[st]);
    }
}
ll nodes[200050];
void dfs_graph(ll root,ll cnt,ll status[200050]){
    status[root]=visited;
    nodes[root]=cnt;
    ll t,i;
    rep(i,0,v[root].size()){
        t=v[root][i].first;
            if(status[t]==initial&&isbridge[v[root][i].second]==0){
                dfs_graph(t,cnt,status);
            }
    }
}
vector<ll> vrt[200050];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    ll i,j,n,m,x,y,cnt=0,status[200050];
    rep(i,0,200050)
        status[i]=initial;
    cin>>n>>m;
    rep(i,0,m){
        ++cnt;
        cin>>x>>y;
        edges.pb(mp(x,y));
        v[x].pb(mp(y,cnt));
        v[y].pb(mp(x,cnt));
    }
    dfs_bridge(1,0,status);
    rep(i,0,200050)
        status[i]=initial;
    cnt=1;
    REP(i,1,n)
        if(status[i]==initial){
            dfs_graph(i,cnt,status);
            ++cnt;
        }
    rep(i,0,200050)
        status[i]=initial;
    ll t,leaf,e=0,d=0;
    for(auto i:edges){
        x=nodes[i.first]; y=nodes[i.second];
        if(x==y)
            continue;
        vrt[x].pb(y);
        vrt[y].pb(x);
        ++e;
    }
    rep(i,0,200050)
        status[i]=initial;
    queue<ll> q;
    q.push(1); status[1]=visited;
    while(!q.empty()){
        t=q.front();
        q.pop();
        rep(i,0,vrt[t].size()){
            x=vrt[t][i];
            if(status[x]==initial){
                q.push(x);
                status[x]=visited;
            }
        }
    }
    leaf=t;
    rep(i,0,200050)
        status[i]=initial;
    q.push(leaf); status[leaf]=visited;
    q.push(0);
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t==0){
            if(q.empty())
                break;
            ++d;
            q.push(0);
        }
        rep(i,0,vrt[t].size()){
            x=vrt[t][i];
            if(status[x]==initial){
                q.push(x);
                status[x]=visited;
            }
        }
    }
    cout<<e<<" "<<d;
    return 0;
}

