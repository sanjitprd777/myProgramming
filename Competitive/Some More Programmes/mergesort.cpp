#include<bits/stdc++.h>
#define ll long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ull unsigned long long int
using namespace std;
ll merge(ll arr[],ll l1,ll u1,ll l2,ll u2){
    ll i=l1,j=l2;
    vector<ll> temp;
    while(i<=u1&&j<=u2){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            ++i;
        }
        else{
            temp.push_back(arr[j]);
            ++j;
        }
    }
    while(i<=u1){
        temp.push_back(arr[i]);
        ++i;
    }
    while(j<=u2){
        temp.push_back(arr[j]);
        ++j;
    }
    for(i=0;i<temp.size();++i)
        arr[i+l1]=temp[i];
}
void merge_sort(ll arr[],ll low,ll high){
    ll mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,mid+1,high);
    }
}
int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n],i;
        for(i=0;i<n;++i)
            cin>>arr[i];
        merge_sort(arr,0,n-1);
        for(i=0;i<n;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
