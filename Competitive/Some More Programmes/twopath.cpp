#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define initial 0
#define waiting 1
#define visited 2
#define nil -1
#define inf 7e+9
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
vector<ll> v2[200050];
map<pair<ll,ll>,ll> edge2;
vector<pair<ll,ll>> edge,v[200050];
ll cnt=0,node[200050],status[200050]={0},comp[200050];
void dfs(ll start,ll cnt){
    node[start]=cnt;
    status[start]=visited;
    ll i,z,c;
    rep(i,0,v[start].size()){
        z=v[start][i].first;
        c=v[start][i].second;
        if(status[z]==initial)
            dfs(z,++cnt);
        if(c)
            node[z]=node[start];
    }
}
void dfs2(ll start,ll cnt){
    comp[start]=cnt;
    status[start]=visited;
    ll i,z,c;
    rep(i,0,v2[start].size()){
        z=v2[start][i];
        if(status[z]==initial)
            dfs2(z,cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    ll n,m,i,x,q,y,a,b,c,d;
    cin>>n>>m>>q;
    while(m--){
        cin>>x>>y>>i;
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
        edge.pb(mp(x,y));
    }
    REP(i,1,n)
        if(status[i]==initial)
             dfs(i,++cnt);

    for(auto it:edge){
        x=it.first; y=it.second;
        x=node[x];  y=node[y];
        auto iit=edge2.find(mp(x,y));
        if(x==y||iit!=edge2.end())
            continue;
        edge2.insert(mp(mp(x,y),1));
        v2[x].pb(y);
        v2[y].pb(x);
    }
    rep(i,0,200050)
        status[i]=initial;
    cnt=0;
    REP(i,1,n)
        if(status[i]==initial){
             dfs2(i,cnt);
             ++cnt;
        }
    while(q--){
        cin>>a>>b>>c>>d;
        a=node[a];  b=node[b];  c=node[c];  d=node[d];
        if(comp[a]!=comp[b])
            cout<<"No";
        else if(comp[c]!=comp[d])
            cout<<"Yes";
        else{

        }
        cout<<endl;
    }

    return 0;
}

