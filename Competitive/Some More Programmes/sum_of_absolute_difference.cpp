using namespace std;
#include <bits/stdc++.h>
#define rep(i,a,n) for( i=a;i<n;i++)
#define repeq(i,a,n) for( i=a;i<=n;i++)
#define reprveq(i,a,n) for( i=a;i>=n;i--)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main() {
    ios_base::sync_with_stdio(false);
   ll t,n,j,k,i;
    ll m=1000000007;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll sum=0;
        sort(arr,arr+n);
        rep(i,0,n)
        {

            sum=(sum%m+((i%m)*(arr[i])%m)%m-((i%m)*(arr[n-i-1])%m)%m+m)%m;

        }
       // sum=((sum%m)*(arr[n-1])%m)%m;
        cout<<sum<<"\n";
    }


  return 0;
}
/*
MY APPROACH
#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ull unsigned long long int
#define mod 1000000007  //1000000009
#define stop return 0;
using namespace std;

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,i,k;
        cin>>n;
        ll arr[n],cum[n];
        for(i=0;i<n;++i)
            cin>>arr[i];
        sort(arr,arr+n);
        cum[0]=0;
        for(i=1;i<n;++i)
            cum[i]=cum[i-1]+arr[i]-arr[0];

        ll ans=cum[n-1];
        for(i=1;i<n;++i){
          //  cout<<ans<<endl;
            ans+=cum[n-1]-(cum[i]+(arr[i]-arr[0])*(n-1-i));
            ans%=mod;
        }
     //   ans=(ans*arr[i-1])%mod;
        cout<<ans<<endl;
    }
    stop;
}
*/
