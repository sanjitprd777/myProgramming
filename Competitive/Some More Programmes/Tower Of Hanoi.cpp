#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
void hanoi(int a,int b,int c,int n){
    if(n>=1){
            hanoi(a,c,b,n-1);
            cout<<"Tower "<<a<<" to Tower "<<c<<endl;
            hanoi(b,a,c,n-1);
    }
}
int main(){
    cout<<"Initial position rod 1 , final destination rod 3"<<endl;
    int n,a=1,b=2,c=3;
    cin>>n;
    if(n==0){
        cout<<"NO rings to move";
        exit(0);
    }
        hanoi(a,b,c,n);
    return 0;
}
