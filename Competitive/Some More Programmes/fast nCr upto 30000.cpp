
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
// we can increase size upto 35000.

int main() {
    long long int i,j,comb[101][101];
    for(i=0;i<=100;++i){
                comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;++j){
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<comb[n+m][m]<<endl;
    }
    return 0;
}
