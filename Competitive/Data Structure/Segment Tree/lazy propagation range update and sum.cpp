#include <bits/stdc++.h>
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

void buildtree(ll start,ll low,ll high,ll arr[],ll segm[]){
    if(low>high)
        return;
    if(low==high){
        segm[start]=arr[low];
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    buildtree(left,low,mid,arr,segm);
    buildtree(right,mid+1,high,arr,segm);
    segm[start]+=segm[left]+segm[right];
}

void update(ll start,ll low,ll high,ll u,ll v,ll val,ll segm[],ll lazy[]){
    if(low>high||low>v||high<u)
        return;
    if(lazy[start]!=0){
        segm[start]+=(high-low+1)*lazy[start];
        if(low!=high){
            lazy[2*start]+=lazy[start];
            lazy[2*start+1]+=lazy[start];
        }
        lazy[start]=0;
    }
    if(low>=u&&high<=v){
        segm[start]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*start]+=val;
            lazy[2*start+1]+=val;
        }
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    update(left,low,mid,u,v,val,segm,lazy);
    update(right,mid+1,high,u,v,val,segm,lazy);
    segm[start]=segm[left]+segm[right];
}
ll query(ll start,ll low,ll high,ll u,ll v,ll segm[],ll lazy[]){
    if(low>high||low>v||high<u)
        return 0;
    if(lazy[start]!=0){
        segm[start]+=lazy[start];
        if(low!=high){
            lazy[2*start]+=lazy[start];
            lazy[2*start+1]+=lazy[start];
        }
        lazy[start]=0;
    }
    if(low>=u&&high<=v)
            return segm[start];
    ll left=2*start,right=left+1,mid=(low+high)/2;
    return query(left,low,mid,u,v,segm,lazy)+query(right,mid+1,high,u,v,segm,lazy);

}

int main(){
   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
   ll n,i,u,v,val,type;
   cin>>n;
   ll arr[n],segm[4*n]={0},lazy[4*n]={0};
   for (i = 0; i < n; ++i)
        cin>>arr[i];
   buildtree(1,0,n-1,arr,segm);
    ll t;
    cin>>t;
    while(t--){
        cin>>type;
        if(type==0){
           cin>>u>>v>>val;
           update(1,0,n-1,u,v,val,segm,lazy);
           continue;
        }
       cin>>u>>v;
       cout<<query(1,0,n-1,u,v,segm,lazy)<<endl;
   }
   return 0;
}
