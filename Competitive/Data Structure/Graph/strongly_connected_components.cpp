// STRONGLY CONNECTED COMPONENTS in directed GRAPH...
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define initial 0
#define waiting 1
#define visited 2
#define fast ios_base::sync_with_stdio(false)
using namespace std;
const ll N=3;
ll n,i,j,temp,start,x,y,count=0;
vector<ll> v[N];
vector<ll> v2[N];
vector<ll> component[N];
stack<ll> s;
ll status[N];
void dfs(ll start,ll &tm){
    ++tm;
    rep1(i,0,v[start].size())
        if(status[v[start][i]]==initial)
            dfs(v[start][i],tm);
    status[start]=visited;
    ++tm;
    s.push(start);
}
void dfs_traversal(){
    rep1(i,0,N)
        status[i]=initial;
    ll tm=0;
    rep1(i,0,N){
      if(status[i]==initial)
        dfs(i,tm);
    }
}
ll k=-1;
void dfs2(ll start){
    status[start]=visited;
    stack<ll> ss;
    ss.push(start);
    component[++k].push_back(start);
    while(!ss.empty()){
        start=ss.top();
        ss.pop();
        status[start]=visited;
        rep1(i,0,v2[start].size())
            if(status[v2[start][i]]==initial){
                ss.push(v2[start][i]);
                status[v2[start][i]]=visited;
                component[k].push_back(v2[start][i]);
            }
    }
    return;
}
void kosarajus_algo(){
    dfs_traversal();
    rep1(i,0,N)
        status[i]=initial;
    while(!s.empty()){
        start=s.top();
        s.pop();
        if(status[start]!=initial)
            continue;
        dfs2(start);
    }
    cout<<k<<endl;
}
int main(){
    cout<<"Enter number of edges"<<endl;
    cin>>n;
    cout<<"Enter all edges"<<endl;
    rep1(i,0,n){
        cin>>x>>y;
        v[x].push_back(y);
        v2[y].push_back(x);
    }
    kosarajus_algo();
    return 0;
}
