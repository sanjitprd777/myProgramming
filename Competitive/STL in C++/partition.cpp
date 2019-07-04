#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> v(100),even(50),odd(50);
    iota(v.begin(),v.end(),1);//insert continue value.

    partition_copy(v.begin(),v.end(),even.begin(),odd.begin(),[](int x){ return x%2==0; });

    for(int i=0;i<even.size();++i){
        cout<<even[i]<<" "<<odd[i]<<endl;
    }
    cout<<endl;

    //reverse the vector
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<endl;
    }
    cout<<endl;

    // partition the same vector according to condition and in stable mode i.e sorted order.
    stable_partition(v.begin(),v.end(),[](int i){ return i%2==0; });
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<endl;
    }
    cout<<endl;
    return 0;
}

