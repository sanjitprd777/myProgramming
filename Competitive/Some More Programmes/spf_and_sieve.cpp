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
#define inf 1.2e+15
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>
#define MAX 10005
#define MAX2 2000005
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
struct node{
    ll even,odd;
};
void buildtree(ll start,ll low,ll high,node segm[],ll arr[]){
    if(low>high)
        return;
    if(low==high){
        if(arr[low]&1){
            segm[start].odd=arr[low];
            segm[start].even=-1;
        }
        else{
            segm[start].even=arr[low];
            segm[start].odd=-1;
        }
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    buildtree(left,low,mid,segm,arr);
    buildtree(right,mid+1,high,segm,arr);
    segm[start].odd=max(segm[left].odd,segm[right].odd);
    segm[start].even=max(segm[left].even,segm[right].even);
}
void update(ll start,ll low,ll high,node segm[],ll arr[],ll idx){
    if(low>high||low>idx||high<idx)
        return;
    if(low==high){
        if(arr[low]&1){
            segm[start].odd=arr[low];
            segm[start].even=-1;
        }
        else{
            segm[start].even=arr[low];
            segm[start].odd=-1;
        }
        return;
    }
    ll left=2*start,right=left+1,mid=(low+high)/2;
    update(left,low,mid,segm,arr,idx);
    update(right,mid+1,high,segm,arr,idx);
    segm[start].odd=max(segm[left].odd,segm[right].odd);
    segm[start].even=max(segm[left].even,segm[right].even);
}
ll query(ll start,ll low,ll high,ll u,ll v,node segm[],ll type){
    if(type==3){
        if(low>high||low>v||high<u)
            return -1;
        if(low>=u&&high<=v)
            return segm[start].odd;

        ll left=2*start,right=left+1,mid=(low+high)/2;
        return max(query(left,low,mid,u,v,segm,type),query(right,mid+1,high,u,v,segm,type));
    }
    else{
        if(low>high||low>v||high<u)
            return -1;
        if(low>=u&&high<=v)
            return segm[start].even;

        ll left=2*start,right=left+1,mid=(low+high)/2;
        return max(query(left,low,mid,u,v,segm,type),query(right,mid+1,high,u,v,segm,type));
    }
}
int main(){
   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
   ll n,q,i,arr[MAX],type,u,v,o,e;
   node segm[4*MAX];
   cin>>n>>q;
   REP(i,1,n)
    cin>>arr[i];
   buildtree(1,1,n,segm,arr);
   while(q--){
        cin>>type>>u>>v;
        if(type==1){
            arr[u]=v;
            update(1,1,n,segm,arr,u);
        }
        else{
            type=query(1,1,n,u,v,segm,type);
            if(type==-1)
                cout<<"DNE"<<endl;
            else
                cout<<type<<endl;
        }

   }
   return 0;
}
