#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#define ll long long int
#define ull unsigned long long int
#define db long double
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>
#define nil -1
#define initial 0
#define waiting 1
#define visited 2
#define inf 10e+9
#define MAX 100005
#define MAX2 1000005
#define MOD 1000000007
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define fast ios_base::sync_with_stdio(false)
using namespace std;
ll solve(ll n){
    ll p=0,q=1;
    ll a,b,c,d,ans[2][2]={p+q,q,q,p},identity[2][2]={1,0,0,1};
    while(n){
        if(n&1){
            a=ans[0][0]*identity[0][0]+ans[0][1]*identity[1][0];
            b=ans[0][0]*identity[0][1]+ans[0][1]*identity[1][1];
            c=ans[1][0]*identity[0][0]+ans[1][1]*identity[1][0];
            d=ans[1][0]*identity[0][1]+ans[1][1]*identity[1][1];
            a%=MOD; b%=MOD; c%=MOD; d%=MOD;
            identity[0][0]=a;  identity[0][1]=b;  identity[1][0]=c;  identity[1][1]=d;
        }
        a=ans[0][0]*ans[0][0]+ans[0][1]*ans[1][0];
        b=ans[0][0]*ans[0][1]+ans[0][1]*ans[1][1];
        c=ans[1][0]*ans[0][0]+ans[1][1]*ans[1][0];
        d=ans[1][0]*ans[0][1]+ans[1][1]*ans[1][1];
        a%=MOD; b%=MOD; c%=MOD; d%=MOD;
        ans[0][0]=a;  ans[0][1]=b;  ans[1][0]=c;  ans[1][1]=d;  n/=2;
    }
    return (identity[0][0]*2+identity[0][1]*1)%MOD;
}
int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int i;
        ll n,ans;
        cin>>n;
        if(n==0)
            ans=1;
        else if(n==1)
            ans=1;
        else if(n==2)
            ans=2;
        else
            ans=solve(n-2);
        cout<<ans<<endl;
    }
    return 0;
}
