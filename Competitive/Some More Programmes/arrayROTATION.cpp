#include <bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;
// step 1. reverse array from begin to "d";
//step 2. reverse array form "d" to end;
// finally reverse whole array.
int main(){
    ll i,d,j,n;
    cin>>n;
    vector <ll> v(n);
    for(i=0;i<n;++i)
    cin>>v[i];
    cin>>d;
    reverse(v.begin(),v.begin()+d);
    for(i=0;i<n;++i)
        cout<<v[i]<<" ";
    cout<<endl;
    reverse(v.begin()+d,v.end());
    for(i=0;i<n;++i)
        cout<<v[i]<<" ";
    cout<<endl;
    reverse(v.begin(),v.end());
    for(i=0;i<n;++i)
        cout<<v[i]<<" ";
    return 0;
}
