#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> v;
    int x,n,i;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter the value to sort in according to absolute difference : ";
    cin>>x;
    //using map to solve this
    // TIME O(n*log(n))
    // SPACE O(n)
    multimap <int,int> m;
    for(i=0;i<v.size();++i)
        m.insert(make_pair(abs(x-v[i]),v[i]));
    for(auto i=m.begin();i!=m.end();++i)
            cout<<(*i).second<<" ";
    return 0;
}
