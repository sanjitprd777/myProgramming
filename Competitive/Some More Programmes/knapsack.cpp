#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#define ll int
#define ull unsigned long long int
#define db long double
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>
#define nil -10e+9
#define initial 0
#define waiting 1
#define visited 2
#define inf 10e+9
#define MAX 105
#define MAX2 1000005
#define MOD 1000000007
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(false)
using namespace std;
ll wt[MAX],val[MAX],n,w,dp[MAX][MAX];
ll solve(ll beg,ll v){
    ll ans;
    if(v<0)
        return nil;
    if(beg==n)
        return 0;
    if(dp[beg][v]!=-1)
        return dp[beg][v];
    ans=max(solve(beg+1,v),val[beg]+solve(beg+1,v-wt[beg]));
    return dp[beg][v]=ans;
}
int main(){
    fast;
    input;
    ll t;
    cin>>t;
    while(t--){
        ll i,j;
        cin>>n>>w;
        rep(i,0,n+5)
            rep(j,0,w+5)
                dp[i][j]=-1;
        rep(i,0,n)
            cin>>wt[i];
        rep(i,0,n)
            cin>>val[i];
        cout<<solve(0,w)<<endl;
    }
    return 0;
}
