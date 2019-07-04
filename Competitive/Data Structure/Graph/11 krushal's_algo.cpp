// KRUSHAL's algorithm using dis-joint sets;
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

pair<ll,pair<ll,ll>> p[100050];
ll status[100050]={0},id[100050];
void make_set(ll n){
    ll i;
    REP(i,0,n)
        id[i]=i;
}
ll find_set(ll x){
    if(id[x]==x)
        return x;
    return id[x]=find_set(id[x]);
}
void union_set(ll x,ll y){
    x=find_set(x);
    y=find_set(y);
    id[x]=id[y]=min(id[x],id[y]);
}
ll mst(ll m){
    ll i,x,y,cost=0,val;
    rep(i,0,m){
        val=p[i].first;
        x=p[i].second.first;
        y=p[i].second.second;
        if(find_set(x)!=find_set(y)){
            cost+=val;
            union_set(x,y);
        }
    }
    return cost;
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    ll n,m,i,j,x,y,w;
    cin>>i;
    cin>>n>>m;
    make_set(n);
    rep(i,0,m){
        cin>>x>>y>>w;
        p[i]=mp(w,mp(x,y));
    }
    sort(p,p+m);
    cout<<mst(m);
    return 0;
}
