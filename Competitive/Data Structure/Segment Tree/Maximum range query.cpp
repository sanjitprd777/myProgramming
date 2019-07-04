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
ll stree[1000]={0};
void buildtree(ll start,ll low,ll high,ll arr[]){
    if (low>high)
        return;
    if(low==high){
        stree[start]=arr[low];
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    buildtree(left,low,mid,arr);
    buildtree(right,mid+1,high,arr);
    stree[start]=max(stree[left],stree[right]);
}

void update(ll start,ll low,ll high,ll arr[],ll idx){
    if (low>high||low>idx||high<idx)
        return;
    if(low==high){
        stree[start]=arr[low];
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    update(left,low,mid,arr,idx);
    update(right,mid+1,high,arr,idx);
    stree[start]=max(stree[left],stree[right]);
}

ll query(ll start,ll low,ll high,ll u,ll v){
    if(low>high||u>v||low>v||high<u)
        return nil;
    if(low>=u&&high<=v)
        return stree[start];
    ll left=2*start,right=left+1,mid=(low+high)/2;
    return max(query(left,low,mid,u,v),query(right,mid+1,high,u,v));
}
int main(){
   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
   ll s,n,q,u,v,val,idx,type,i;
   cin>>n;
   ll arr[n];
   for(i=0;i<n;++i)
     cin>>arr[i];
   buildtree(1,0,n-1,arr);
   cin>>q;
   while(q--){
        cin>>type;
        if(type==0){
            cin>>idx>>val;
            arr[idx]=val;
            update(1,0,n-1,arr,idx);
        }
        else{
            cin>>u>>v;
            cout<<query(1,0,n-1,u,v)<<endl;
        }
   }

   return 0;
}
