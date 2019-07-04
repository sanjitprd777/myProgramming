#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define stop return 0
//#define getchar_unlocked getchar
using namespace std;
int sI(){
        register int c = getchar_unlocked(); //  c = getchar_unlocked_unlocked();
        bool flag = true;
        if(c=='-'){
            flag =false;
            c = getchar_unlocked();
        }
        int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        if(flag){
            return n;
        }
        else{
            return n*-1;
        }
}
long long sLL(){
        register int c = getchar_unlocked();
        bool flag = true;
        if(c=='-'){
            flag =false;
            c = getchar_unlocked();
        }
        long long n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        if(flag){
            return n;
        }
        else{
            return n*-1;
        }
}
void s1(){
        register int c = getchar_unlocked();
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() );
}
ll quick(ll arr[],ll low,ll up){
    ll i,j,mid,pivot;
    i=low+1;
    j=up;
    mid=(low+up)/2;
    if(arr[low]>arr[mid])
        swap(arr[low],arr[mid]);
    if(arr[low]>arr[up])
        swap(arr[low],arr[up]);
    if(arr[mid]>arr[up])
        swap(arr[mid],arr[up]);
    pivot=arr[low];
    while(i<=j){
        while(arr[i]<pivot)
            ++i;
        while(arr[j]>pivot)
            --j;
        if(i<j){
            swap(arr[i],arr[j]);
            ++i;  --j;
        }
        else
            ++i;
    }
    swap(arr[j],arr[low]);
    return j;
}
void quick_sort(ll arr[],ll low,ll up){
    if(up>low){
        ll pivot=quick(arr,low,up);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,up);
    }
}
int main()
{
    fast;
        ll n,i;
        n=sLL();
        ll arr[n];
        rep(i,0,n){
            arr[i]=sLL();
        }
        quick_sort(arr,0,n-1);
        rep(i,0,n)
            cout<<arr[i]<<" ";

    stop;
}
