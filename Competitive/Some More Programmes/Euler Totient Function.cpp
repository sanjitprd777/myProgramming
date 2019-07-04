//this function is use to calculate negative inverse when mod is not prime and we cal phi of ( mod ) if not prime.
#include <iostream>
#define ll long long int
using namespace std;
ll phi(ll n){
    ll i,res=n;
    for(i=2;i*i<=n;++i)
        if(n%i==0){
         while(n%i==0)
            n/=i;   // reducing n by spf of (n)
        res=res*(i-1)/i;    // removing all multiples of prime (i)
    }
    if(n>1) // means n is prime
        res=res*(n-1)/n;  // removing all multiples of prime (n)
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<phi(n)<<endl;
    return 0;
}
