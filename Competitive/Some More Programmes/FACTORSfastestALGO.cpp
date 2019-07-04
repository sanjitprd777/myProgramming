#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
ll check_prime(ll n){
    if(n<=1)
        return 0;
    if(n<=3)
        return 1;
    if(n%2==0||n%3==0)
        return 0;
    for(ll i=5;i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0)
            return 0;
    return 1;
}
int main(){
    ll i,prime[10000],arr[100000]={0},temp,res=0,k=0,p,c,j,a,b,n,ans;
    //sieve to calculate prime numbers upto 10^6.
    for(i=0;i<100000;++i)
        arr[i]=i;
    arr[0]=arr[1]=0;
    for(i=0;i<100000;++i)
        if(arr[i]){
            prime[k++]=i;
              for(j=2*i;j<100000;j+=i)
                    arr[j]=0;
      }
    int t;
    cin>>t;
    while(t--){
    cin>>a;
    for(j=a;j<=a;++j){
        i=j;
        ans=1;   k=0;
        while(prime[k]){
            p=prime[k];
            if(p*p*p>i)
                break;
            c=1;
            while(i%p==0){
                i/=p;
                ++c;
            }
            ans*=c;
            ++k;
        }
    ll l=sqrt(i);
    if(i<100000){
        if(arr[i])
        ans*=2;
    else if(l*l==i&&arr[l])
        ans*=3;
    else if(i!=1)
        ans*=4;
    }
    else{
     if(check_prime(i))
        ans*=2;
    else if(l*l==i&&check_prime(l))
        ans*=3;
    else if(i!=1)
        ans*=4;
    }
    }
    cout<<ans<<endl;
    }
    return 0;
}

