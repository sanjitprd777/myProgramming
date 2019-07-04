#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define pb push_back
#define mp make_pair
#define initial 1
#define waiting 2
#define visited 3
#define nil -1
#define inf 7e+9
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
vector<pair<ll,ll>> ae;
vector<ll> v[20],ap;
ll par[20],vis[20],low[20],status[20]={0};;
void tarjans_algo(ll x,ll timer){
    status[x]=visited;
    vis[x]=low[x]=timer+1;
    ll child=0;
    ll i,t;
    rep(i,0,v[x].size()){
        t=v[x][i];
        if(status[t]==initial){
            ++child;
            par[t]=x;
            tarjans_algo(t,timer+1);
            low[x]=min(low[x],low[t]);
            if(par[x]==nil&&child>1)
              ap.pb(x);
            if(par[x]!=nil&&vis[x]<=low[t])
              ap.pb(x);
            if(vis[x]<low[t])
                ae.pb(mp(x,t));
        }
        else if(par[x]!=t)
            low[x]=min(low[x],vis[t]);
    }
}
bool comp(pair<ll,ll> p,pair<ll,ll> q){
    if(p.first<q.first)
        return true;
    if(p.second<q.second)
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    ll n,m,x,y,i;
    cin>>n>>m;
    rep(i,0,m){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        status[x]=status[y]=initial;
    }
    par[0]=nil;
    tarjans_algo(0,0);
    rep(i,0,ae.size()){
        x=min(ae[i].first,ae[i].second);
        y=max(ae[i].first,ae[i].second);
        ae[i].first=x;
        ae[i].second=y;
    }

    sort(ap.begin(),ap.end());
    sort(ae.begin(),ae.end(),comp);
    cout<<ap.size()<<endl;
    rep(i,0,ap.size())
        cout<<ap[i]<<endl;
    cout<<ae.size()<<endl;
    rep(i,0,ae.size())
        cout<<ae[i].first<<" "<<ae[i].second<<endl;
    return 0;
}
