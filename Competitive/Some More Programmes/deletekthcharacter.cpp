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
#define MAX 300005
#define MAX2 2000005
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,m,i,j;
        string a,b;
        cin>>n>>m;
        cin>>a>>b;
        ll dp[n+2][m+2]={0};
        for(i=0;i<n+1;++i)
            for(j=0;j<m+1;++j)
                dp[i][j]=0;
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                if(a[i]==b[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        cout<<dp[n][m]<<endl;
    }

    return 0;
}
