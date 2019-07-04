#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int prime(ll int n){
    ll int i,c=0;
    if(n%2==0){
        ++c;
        cout<<"2"<<endl;
        while(n%2==0)
            n/=2;
    }
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0){
            ++c;
            cout<<i<<endl;
        }
        while(n%i==0)
            n/=i;
    }
	if (n > 2){
        ++c;
		cout<<n<<endl;
	}
    return c;
}
int main() {
    ll int n;
    cin>>n;
    cout<<"Numbers of distinct prime factors : "<<prime(n);
    return 0;
}
