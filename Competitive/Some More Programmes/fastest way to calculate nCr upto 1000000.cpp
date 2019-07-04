#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ull power(ull a,ull b){
    ull ans=1;
    if(b==0)
        return 1;
    while(b){
        if(b&1)
             ans=(ans*a)%mod;

        a=(a*a)%mod;
        b/=2;
     }
    return (ans)%mod;
}
int main() {
    ull fact[200001],i,j,m,n,t,num,den,ans;
    fact[0]=1;
    for(i=1;i<200000;++i)
        fact[i]=(fact[i-1]*i)%mod;
    cin>>t;
    cout<<"Enter the value of N and R : "<<endl;
        cin>>m>>n;
        num=fact[m+n];
        den=(fact[m]*fact[n])%mod;
        ans=(num*power(den,mod-2))%mod;
        cout<<ans<<endl;

    return 0;
}
