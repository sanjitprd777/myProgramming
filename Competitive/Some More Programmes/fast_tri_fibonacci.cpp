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
    ll i,j,k,ans[3][3]={1,1,1,1,0,0,0,1,0},res[3][3]={1,0,0,0,1,0,0,0,1},m[3][3];
    while(n){
        if(n&1){
            rep(i,0,3)
                rep(j,0,3){
                    m[i][j]=0;
                    rep(k,0,3)
                        m[i][j]=(m[i][j]+ans[i][k]*res[k][j])%MOD;
                }
            rep(i,0,3){
                rep(j,0,3){
                    res[i][j]=m[i][j]%MOD;
                   // cout<<res[i][j]<<" ";
                }
               // cout<<endl;
            }
        }
        rep(i,0,3)
            rep(j,0,3){
                m[i][j]=0;
                rep(k,0,3)
                    m[i][j]=(m[i][j]+ans[i][k]*ans[k][j])%MOD;
            }
            rep(i,0,3){
                rep(j,0,3){
                    ans[i][j]=m[i][j]%MOD;
                //    cout<<ans[i][j]<<" ";
                }
              //  cout<<endl;
            }
        n/=2;
    }
    return (res[0][0]*7+res[0][1]*4+res[0][2]*2)%MOD;
}
int main(){
   // input;
    fast;
    int t;
    cin>>t;
    while(t--){
        int i;
        ll n,ans;
        cin>>n;
        if(n==1)
            ans=2;
        else if(n==2)
            ans=4;
        else if(n==3)
            ans=7;
        else
            ans=solve(n-3);
        cout<<ans<<endl;
    }
    return 0;
}
