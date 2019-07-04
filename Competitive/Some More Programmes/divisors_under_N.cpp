#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define fast ios_base::sync_with_stdio(false)
using namespace std;
struct node{
    ll val,index,cnt;
    node(ll v,ll i,ll cc):val(v),index(i),cnt(cc){ }
};
int main(){
    ll ans=0,y,n,k=-1,N,t,v,m,i,x=1,j;
    cin>>N;
    cin>>n;
    ll arr[100];
    rep1(i,0,n)
        cin>>arr[i];
    vector<node> s;
    ll c=2;
    rep1(i,0,n){
        x=arr[i];
        rep1(j,i+1,n)
            s.push_back(node((x*arr[j])/__gcd(x,arr[j]),j,c));
    }
    x=0;
    y=s.size();
    ++c;
    while(1){
        rep1(i,x,y){
           t=s[i].index;
           v=s[i].val;
           rep1(j,t+1,n)
                s.push_back(node((v*arr[j])/__gcd(v,arr[j]),j,c));
        }
        if(y==s.size())
            break;
        else{
            ++c;
            x=y;
            y=s.size();
        }
    }
    rep1(i,0,n){
        ans+=N/arr[i];
       // cout<<ans<<"   "<<arr[i]<<endl;
    }
    //cout<<"hai"<<endl;
    rep1(i,0,s.size()){
      if(s[i].cnt%2==0)
        ans-=N/s[i].val;
      else
        ans+=N/s[i].val;
     //   cout<<ans<<"   "<<s[i].val<<endl;
    }
    cout<<fixed<<ans;
    return 0;
}
