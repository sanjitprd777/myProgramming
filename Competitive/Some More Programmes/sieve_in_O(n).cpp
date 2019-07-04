#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define nil -10e+9
#define initial 0
#define waiting 1
#define visited 2
#define inf 10e+9
#define mx 1005
#define mxx 100000001
#define mod 1000000007
#define pr pair<ll,ll>
#define fr(i,p,q) for(int i=p;i<q;++i)
#define frr(i,p,q) for(int i=p;i<=q;++i)
#define mem(a,b) memset(a,b,sizeof(a))
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int lp[mx]={0},pm[mx]={0},cnt=0;
    fr(i,2,mx){
        if(lp[i]==0)
            lp[i]=i,pm[cnt]=i,cnt++;
        for(int j=0;j<cnt&&(i*pm[j]<mx)&&(pm[j]<=lp[i]);++j)
            lp[i*pm[j]]=pm[j];
    }
    fr(i,0,cnt)
        cout<<pm[i]<<endl;
    return 0;
}
