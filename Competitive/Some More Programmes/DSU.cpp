#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#define ll long long int
#define ull unsigned long long int
#define db long double
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define pb push_back
#define nil -1
#define initial 0
#define waiting 1
#define visited 2
#define inf 10e+9
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>
#define MAX 1005
#define MAX2 2000005
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
ll par[MAX],sz[MAX];
ll root(ll x){
    if(par[x]==x)
        return x;
    return par[x]=root(par[x]);
}
void merge(ll x,ll y){
    x=root(x);  y=root(y);
    if(x==y)    return;
    if(sz[x]<sz[y])    swap(x,y);
    sz[x]+=sz[y];
    par[y]=x;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    //freopen("input.txt", "r", stdin); // redirects standard input
    //freopen("output.txt", "w", stdout); // redirects standard output
    ll n,m,i,a,b;
    cin>>n>>m;
    REP(i,1,n){
        par[i]=i;
        sz[i]=1;
    }
    rep(i,0,m){
        cin>>a>>b;
        merge(a,b);
    }
    return 0;
}
