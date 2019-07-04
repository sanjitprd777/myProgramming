#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void heapify_down(ll arr[],ll pos,ll hsize){
    ll lchild=2*pos,rchild=2*pos+1,num=arr[pos];
    while(rchild<=hsize){
        if(num>=arr[lchild]&&num>=arr[rchild])
            return;
        else if(arr[lchild]>arr[rchild]){
            arr[pos]=arr[lchild];
            pos=lchild;
        }
        else{
            arr[pos]=arr[rchild];
            pos=rchild;
        }
        lchild=2*pos;
        rchild=lchild+1;
    }
    if(lchild==hsize&&num<arr[lchild]){
        arr[pos]=arr[lchild];
        pos=lchild;
    }
    arr[pos]=num;
}
void heapify(ll arr[],ll &hsize){
    for(ll i=hsize/2;i>0;--i)
        heapify_down(arr,i,hsize);
}
void heap_sort(ll arr[],ll hsize){
    while(hsize>1){
        int pos=1,num=arr[pos];
        swap(arr[pos],arr[hsize]);
        hsize--;
        heapify_down(arr,pos,hsize);
    }
}
int  main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i,arr[n+1],hsize=n;
        for(i=1;i<=n;++i)
            cin>>arr[i];
        //heapify array in bottom_up approach ...
        heapify(arr,hsize);
        cout<<"Heapify array is : "<<endl;
        for(i=1;i<=hsize;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
        //Applying heap_sort...
        heap_sort(arr,hsize);
        cout<<"Sorted array is : "<<endl;
        for(i=1;i<=hsize;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
