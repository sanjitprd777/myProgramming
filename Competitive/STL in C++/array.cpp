#include <bits/stdc++.h>
#include <numeric>
#include <array>
using namespace std;
int main(){
    array <int,10> arr;
    cout<<"Size of array is : "<<arr.size()<<endl;

    arr.fill(5);  //in vector v.asign(10,222);
    cout<<endl;
    for(int i=0;i<arr.size();++i)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<arr.front()<<"\n";//prints first value.
    cout<<arr.back()<<endl; //prints last value.

    //we can also swap two arrays using arr1.swap(arr2);
    //arr1 and arr2 have same size and data type.

    array <int,20> arr1,arr2;

    //to check if array is empty i.e size zero
    if(arr1.empty())
        cout<<"YES ARRAY IS EMPTY"<<endl;
    else
        cout<<"NO ARRAY IS NOT EMPTY"<<endl;

    //fill the array with continue values, i.e no need of loop
    iota(arr1.begin(),arr1.end(),1);       //add values 1 2 3 4 ... arr.size().

    //deep copy array to another array , use 3 iterators.
    copy_n(arr1.begin(),arr1.size(),arr2.begin());

    for(int i=0;i<arr2.size();++i)
        cout<<arr2[i]<<" ";

    //swap two array.
    swap(arr1,arr2);

    return 0;
}
