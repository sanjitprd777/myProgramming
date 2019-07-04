#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    vector <int> v1(5);//create 5 size vector.
    vector <int> v2;
    v2.assign(5,88);        //create 5 size vector and fill all with 88 .  Same as arr.fill(4).
    iota(v1.begin(),v1.end(),1);

    vector <int> v3 {1,2,3,4,5};//create 5 size vector initializing initially.
    cout<<v2.size()<<endl;// gives number of elements in the array.
    cout<<v1.capacity()<<endl;// gives size of vector irrespective of number of elements but it size if initially given than same is ans.

    cout<<v2.front()<<" "<<v3.back()<<endl; //first and last element.
    //to insert data in between.
    vector <int>:: iterator it=v3.begin();//the iterator it points to first element of vector.
    v3.insert(it+2,55);// it will insert value 55 after 2 block i.e at block third.
    cout<<v3.at(3)<<endl;
    vector <float> vv;
    for(int i=0;i<1000000;++i)
        vv.push_back(i);
    cout<<vv.size()<<" "<<vv.capacity()<<endl;//here size and capacity is different bcz size is not given initially.
    vv.pop_back();
    cout<<vv.size()<<"  "<<vv.capacity()<<endl;//After poping size change but capacity remains unchanged.
    //to traverse last to first using reverse_iterator
    vector <int>:: reverse_iterator i=v2.rbegin();
    while(i!=v2.rend()){
        cout<<*i<<" ";
        ++i;
    }
    cout<<endl;
    swap(v1,v2); //swapped two vectors.

     int gfg[] = {5,6,7,7,6,5,5,6};

    vector<int> v(gfg,gfg+8);    // 5 6 7 7 6 5 5 6 copying array to vector.

    sort (v.begin(), v.end());  // 5 5 5 6 6 6 7 7

    vector<int>::iterator lower,upper;
    lower = lower_bound (v.begin(), v.end(), 6);
    upper = upper_bound (v.begin(), v.end(), 6);

    cout << "lower_bound for 6 at position " << (lower- v.begin()) << '\n';
    cout << "upper_bound for 6 at position " << (upper - v.begin()) << '\n';

    copy_n(v1.begin(),v1.size(),v2.begin());//copy vector v2 in v1;
    for(int i=0;i<v1.size();++i)
        cout<<v1[i]<<" "<<v2[i]<<endl;
    return 0;
}
