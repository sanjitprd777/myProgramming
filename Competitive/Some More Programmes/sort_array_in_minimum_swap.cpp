#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll count_swap(vector<ll> a,vector<ll> b,ll n){
    ll count=0,cv,scv,i;
    map<ll,ll> m;
    for(i=0;i<n;++i)
        m[a[i]]=i;
    for(i=0;i<n;++i)
        if(a[i]!=b[i]){
            cv=a[i];
            scv=b[i];
            swap(a[i],a[m[scv]]);
            m[cv]=m[scv];
            count++;
        }
    return count;
}
int main(){
    ll j,t;
    cin>>t;
    for(j=1;j<=t;++j){
        ll ans,n,i;
        cin>>n;
        vector<ll> arr(n),brr(n);
        for(i=0;i<n;++i){
            cin>>arr[i];
            brr[i]=arr[i];
        }
        sort(brr.begin(),brr.end());
        ans=count_swap(arr,brr,n);
        cout<<ans<<endl;
    }
    return 0;
}
